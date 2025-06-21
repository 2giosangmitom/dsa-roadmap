#!/usr/bin/env python3

import argparse
import subprocess
import os
import sys
import re

# ANSI color codes for enhanced output formatting
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
RESET = "\033[0m"
BOLD = "\033[1m"

os.environ["CXX"] = "clang++"


def print_color(msg, color=RESET, bold=False, file=sys.stdout, end="\n"):
    style = color + (BOLD if bold else "")
    print(f"{style}{msg}{RESET}", file=file, end=end)


def run_command(cmd, cwd=None, dry=False, verbose=True):
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
        if not verbose and e.stdout:
            print(e.stdout.decode(), file=sys.stderr)
        if not verbose and e.stderr:
            print(e.stderr.decode(), file=sys.stderr)
        sys.exit(e.returncode)


def build(target, dry=False):
    run_command(["cmake", "-B", "build", "-GNinja"], dry=dry)
    build_cmd = ["cmake", "--build", "build"]
    if target != "all":
        build_cmd += ["--target", f"solutions_{target}_test"]
    run_command(build_cmd, dry=dry)


def test(target, dry=False, verbose=False):
    dir_path = os.path.join("build", "bin")
    if not os.path.isdir(dir_path):
        print_color(
            f"Test directory '{dir_path}' does not exist. Please build first.",
            RED,
            bold=True,
            file=sys.stderr,
        )
        sys.exit(1)

    def run_test(file_path):
        print_color(f"▶ Running {file_path}", YELLOW)
        if dry:
            return 0
        ret = subprocess.call(
            file_path,
            stdout=None if verbose else subprocess.DEVNULL,
            stderr=None if verbose else subprocess.DEVNULL,
        )
        if ret == 0:
            print_color(f"✓ {os.path.basename(file_path)} PASSED", GREEN, bold=True)
        else:
            print_color(
                f"✗ {os.path.basename(file_path)} FAILED (exit {ret})",
                RED,
                bold=True,
                file=sys.stderr,
            )
        return ret

    if target == "all":
        files = [
            os.path.join(dir_path, f)
            for f in os.listdir(dir_path)
            if os.access(os.path.join(dir_path, f), os.X_OK)
            and os.path.isfile(os.path.join(dir_path, f))
        ]
        if not files:
            print_color(
                f"No executables found in '{dir_path}'.",
                RED,
                bold=True,
                file=sys.stderr,
            )
            sys.exit(1)
        any_failed = False
        for file_path in sorted(files):
            if run_test(file_path) != 0:
                any_failed = True
        if any_failed:
            sys.exit(1)
    else:
        file_path = os.path.join(dir_path, f"solutions_{target}_test")
        if not os.path.isfile(file_path) or not os.access(file_path, os.X_OK):
            print_color(
                f"Test executable '{file_path}' not found or not executable.",
                RED,
                bold=True,
                file=sys.stderr,
            )
            sys.exit(1)
        if run_test(file_path) != 0:
            sys.exit(1)


def add_solution(problem_number, dry=False):
    hpp_dir = f"src/solutions_{problem_number}"
    hpp_path = f"{hpp_dir}/solutions_{problem_number}.hpp"
    test_path = f"{hpp_dir}/solutions_{problem_number}_test.cc"

    if os.path.exists(hpp_path) or os.path.exists(test_path):
        print_color("Solution files already exist.", RED, bold=True, file=sys.stderr)
        sys.exit(1)
    if dry:
        print_color(f"Would create: {hpp_path}", CYAN)
        print_color(f"Would create: {test_path}", CYAN)
        return

    os.makedirs(hpp_dir, exist_ok=True)
    # OLD TEMPLATE (unchanged class name)
    with open(hpp_path, "w") as hpp_file:
        hpp_file.write("""#pragma once

class Solution {
public:
};
""")
    print_color(f"Created {hpp_path}", GREEN)

    with open(test_path, "w") as test_file:
        test_file.write(f"""#include "solutions_{problem_number}.hpp"
#include <gtest/gtest.h>
""")
    print_color(f"Created {test_path}", GREEN)


def check_readme():
    src_dir = "src"
    pattern = re.compile(r"solutions_(\d+)\.hpp$")
    missing = []
    all_solutions = []
    for root, _, files in os.walk(src_dir):
        for file in files:
            match = pattern.match(file)
            if match:
                num = match.group(1)
                rel_path = os.path.relpath(os.path.join(root, file), start=".")
                all_solutions.append((num, rel_path))

    if not all_solutions:
        print_color("No solutions found in src/.", RED, bold=True, file=sys.stderr)
        sys.exit(1)

    with open("README.md", "r", encoding="utf-8") as f:
        readme = f.read()

    for num, path in all_solutions:
        if path not in readme and f"solutions_{num}" not in readme:
            missing.append((num, path))

    if not missing:
        print_color(
            "All solutions in src/ are included in README.md.", GREEN, bold=True
        )
    else:
        print_color("Missing solutions in README.md:", RED, bold=True)
        for _, path in missing:
            print_color(f"  - {path}", YELLOW)
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser(description="LeetCode Repository Manager")
    parser.add_argument(
        "--dry", action="store_true", help="Print commands instead of executing"
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    build_parser = subparsers.add_parser("build", help="Build the project or a target")
    build_parser.add_argument(
        "target", help="Target to build (use 'all' for all targets)"
    )

    test_parser = subparsers.add_parser(
        "test", help="Test all binaries or a specific target"
    )
    test_parser.add_argument(
        "target", help="Test target (use 'all' for all executables)"
    )
    test_parser.add_argument(
        "--verbose", action="store_true", help="Show test output instead of hiding it"
    )

    add_parser = subparsers.add_parser("add", help="Add a new solution")
    add_parser.add_argument("problem_number", help="Problem number to add")

    subparsers.add_parser("check", help="Check all solutions are in README.md")

    args = parser.parse_args()

    if args.command == "build":
        build(args.target, dry=args.dry)
    elif args.command == "test":
        test(args.target, dry=args.dry, verbose=args.verbose)
    elif args.command == "add":
        add_solution(args.problem_number, dry=args.dry)
    elif args.command == "check":
        check_readme()


if __name__ == "__main__":
    main()
