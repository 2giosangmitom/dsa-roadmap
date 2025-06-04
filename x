#!/usr/bin/env python3

import argparse
import subprocess
import os
import sys

# ANSI color codes
GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
RESET = "\033[0m"
BOLD = "\033[1m"

# Specify C++ compiler to clang++
os.environ["CXX"] = "clang++"


def print_color(msg, color=RESET, bold=False, file=sys.stdout, end="\n"):
    style = color + (BOLD if bold else "")
    print(f"{style}{msg}{RESET}", file=file, end=end)


def run_command(cmd, cwd=None, dry=False, verbose=True):
    print_color(f"Running: {' '.join(cmd)}", CYAN, bold=True)
    if dry:
        return 0
    try:
        if verbose:
            result = subprocess.run(cmd, check=True, cwd=cwd)
        else:
            result = subprocess.run(
                cmd, check=True, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE
            )
        return result.returncode
    except subprocess.CalledProcessError as e:
        print_color(f"Command failed: {' '.join(cmd)}", RED, bold=True, file=sys.stderr)
        print_color(f"Error: {e}", RED, file=sys.stderr)
        if verbose and hasattr(e, "output"):
            # In verbose mode, output should already have been shown
            pass
        elif hasattr(e, "stdout") and e.stdout:
            print(e.stdout.decode(), file=sys.stderr)
        elif hasattr(e, "stderr") and e.stderr:
            print(e.stderr.decode(), file=sys.stderr)
        sys.exit(e.returncode)


def build(target, dry=False):
    run_command(["cmake", "-B", "build"], dry=dry)
    if target == "all":
        run_command(["cmake", "--build", "build"], dry=dry)
    else:
        run_command(["cmake", "--build", "build", "--target", target], dry=dry)


def test(target, dry=False, verbose=False):
    dir_path = os.path.join("build", "bin")
    if not os.path.isdir(dir_path):
        print_color(
            f"Test directory '{dir_path}' does not exist. Build first.",
            RED,
            bold=True,
            file=sys.stderr,
        )
        sys.exit(1)

    def run_test(file_path):
        print_color(f"Running {file_path}", YELLOW)
        if dry:
            return 0
        if verbose:
            ret = subprocess.call(file_path)
        else:
            ret = subprocess.call(
                file_path, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL
            )
        if ret == 0:
            print_color(f"Test {file_path} PASSED", GREEN, bold=True)
        else:
            print_color(
                f"Test {file_path} FAILED with exit code {ret}",
                RED,
                bold=True,
                file=sys.stderr,
            )
        return ret

    if target == "all":
        files = [
            f
            for f in os.listdir(dir_path)
            if os.access(os.path.join(dir_path, f), os.X_OK)
        ]
        if not files:
            print_color(
                f"No executables found in '{dir_path}'.",
                RED,
                bold=True,
                file=sys.stderr,
            )
            sys.exit(1)
        failed = False
        for file in files:
            file_path = os.path.join(dir_path, file)
            ret = run_test(file_path)
            if ret != 0:
                failed = True
        if failed:
            sys.exit(1)
    else:
        file_path = os.path.join(dir_path, target)
        if not os.path.isfile(file_path) or not os.access(file_path, os.X_OK):
            print_color(
                f"Test executable '{file_path}' not found or not executable.",
                RED,
                bold=True,
                file=sys.stderr,
            )
            sys.exit(1)
        ret = run_test(file_path)
        if ret != 0:
            sys.exit(ret)


def main():
    parser = argparse.ArgumentParser(description="Build and test LeetCode solutions")
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

    args = parser.parse_args()

    if args.command == "build":
        build(args.target, dry=args.dry)
    elif args.command == "test":
        test(args.target, dry=args.dry, verbose=args.verbose)


if __name__ == "__main__":
    main()
