#!/usr/bin/env python

import argparse
import os
import subprocess
import sys
from pathlib import Path
from textwrap import dedent, shorten
import re
import asyncio

# Terminal colors
GREEN, RED, YELLOW, CYAN, RESET, BOLD = (
    "\033[92m",
    "\033[91m",
    "\033[93m",
    "\033[96m",
    "\033[0m",
    "\033[1m",
)

os.environ["CXX"] = "clang++"
ANSI_ESCAPE = re.compile(r"\x1b\[[0-9;]*m")


def strip_ansi(text: str) -> str:
    return ANSI_ESCAPE.sub("", text)


def print_color(msg, color=RESET, bold=False, end="\n", file=sys.stdout):
    print(f"{color}{BOLD if bold else ''}{msg}{RESET}", file=file, end=end)


def print_table(headers, rows):
    widths = [
        max(len(strip_ansi(str(cell))) for cell in col) for col in zip(headers, *rows)
    ]
    sep = "+-" + "-+-".join("-" * w for w in widths) + "-+"

    def format_row(row):
        return (
            "| "
            + " | ".join(
                f"{cell}{' ' * (widths[i] - len(strip_ansi(str(cell))))}"
                for i, cell in enumerate(row)
            )
            + " |"
        )

    print(f"{sep}\n{format_row(headers)}\n{sep}")
    for row in rows:
        print(format_row(row))
    print(sep)


def run_command(cmd, dry=False, verbose=True, cwd=None):
    print_color(f"$ {' '.join(cmd)}", CYAN, bold=True)
    if dry:
        return 0

    try:
        result = subprocess.run(
            cmd,
            check=True,
            cwd=cwd,
            stdout=None if verbose else subprocess.PIPE,
            stderr=None if verbose else subprocess.PIPE,
        )
        return result.returncode
    except subprocess.CalledProcessError as e:
        print_color(
            f"✗ Command failed: {' '.join(cmd)}", RED, bold=True, file=sys.stderr
        )
        if not verbose:
            if e.stdout:
                sys.stderr.write(e.stdout.decode())
            if e.stderr:
                sys.stderr.write(e.stderr.decode())
        sys.exit(e.returncode)


def build(args):
    run_command(["cmake", "-B", "build", "-GNinja"], dry=args.dry)
    cmd = ["cmake", "--build", "build"]
    if args.target != "all":
        cmd += ["--target", f"solutions_{args.target}_test"]
    run_command(cmd, dry=args.dry)


async def run_single_test(file_path: Path, verbose=False, dry=False):
    name = file_path.name
    if dry:
        return [name, "DRY RUN", "Skipped execution"], 0

    proc = await asyncio.create_subprocess_exec(
        str(file_path),
        stdout=None if verbose else asyncio.subprocess.DEVNULL,
        stderr=None if verbose else asyncio.subprocess.DEVNULL,
    )
    retcode = await proc.wait()
    status = f"{GREEN}PASSED{RESET}" if retcode == 0 else f"{RED}FAILED{RESET}"
    return [name, status, f"Exit code: {retcode}"], retcode


def test(args):
    bin_dir = Path("build/bin")
    if not bin_dir.is_dir():
        print_color(
            f"Test directory '{bin_dir}' does not exist. Please build first.",
            RED,
            bold=True,
            file=sys.stderr,
        )
        sys.exit(1)

    test_files = (
        sorted(f for f in bin_dir.iterdir() if f.is_file() and os.access(f, os.X_OK))
        if args.target == "all"
        else [bin_dir / f"solutions_{args.target}_test"]
    )

    for tf in test_files:
        if not tf.exists() or not os.access(tf, os.X_OK):
            print_color(
                f"Test executable '{tf}' not found or not executable.", RED, bold=True
            )
            sys.exit(1)

    async def run_all_tests():
        tasks = [run_single_test(f, args.verbose, args.dry) for f in test_files]
        results = await asyncio.gather(*tasks)

        summary = [r for r, _ in results]
        failed = any(ret != 0 for _, ret in results)

        print()
        print_color("Test Results Summary:", bold=True)
        print_table(["Test Executable", "Status", "Details"], summary)
        print(f"{BOLD}Total: {len(summary)} files{RESET}")

        if failed:
            sys.exit(1)

    asyncio.run(run_all_tests())


def add(args):
    problem = args.problem_number
    hpp_dir = Path(f"src/solutions_{problem}")
    hpp_path = hpp_dir / f"solutions_{problem}.hpp"
    test_path = hpp_dir / f"solutions_{problem}_test.cc"

    if hpp_path.exists() or test_path.exists():
        print_color("Solution files already exist.", RED, bold=True, file=sys.stderr)
        sys.exit(1)

    if args.dry:
        print_color(f"Would create: {hpp_path}", CYAN)
        print_color(f"Would create: {test_path}", CYAN)
        return

    hpp_dir.mkdir(parents=True, exist_ok=True)
    hpp_path.write_text(
        dedent("""\
        #pragma once

        class Solution {
        public:
        };
    """)
    )
    print_color(f"Created {hpp_path}", GREEN)

    test_path.write_text(
        f'#include "solutions_{problem}.hpp"\n#include <gtest/gtest.h>\n'
    )
    print_color(f"Created {test_path}", GREEN)


def check_readme(args=None):
    solutions = list(Path("src").glob("solutions_*/solutions_*.hpp"))
    if not solutions:
        print_color("No solutions found in src/.", RED, bold=True, file=sys.stderr)
        sys.exit(1)

    readme = Path("README.md").read_text(encoding="utf-8")
    missing = [str(p) for p in solutions if str(p) not in readme]

    if not missing:
        print_color("✓ All solutions are included in README.md", GREEN, bold=True)
    else:
        print_color("✗ Missing solutions in README.md:", RED, bold=True)
        print_table(
            ["Solution File", "README Status"],
            [[shorten(p, 60), f"{RED}NOT FOUND{RESET}"] for p in missing],
        )
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser(
        prog="x",
        description="📦 LeetCode C++ Project Manager",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--dry", action="store_true", help="Print commands instead of executing"
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    # build
    sp = subparsers.add_parser("build", help="Build the project or a specific target")
    sp.add_argument("target", help="Target to build (e.g. 123 or 'all')")
    sp.set_defaults(func=build)

    # test
    sp = subparsers.add_parser("test", help="Run test executables")
    sp.add_argument("target", help="Test target (e.g. 123 or 'all')")
    sp.add_argument(
        "--verbose", action="store_true", help="Show output from test binaries"
    )
    sp.set_defaults(func=test)

    # add
    sp = subparsers.add_parser("add", help="Create a solution + test skeleton")
    sp.add_argument("problem_number", help="Problem number to add")
    sp.set_defaults(func=add)

    # check
    sp = subparsers.add_parser(
        "check", help="Check all solutions are listed in README.md"
    )
    sp.set_defaults(func=check_readme)

    args = parser.parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
