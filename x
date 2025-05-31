#!/usr/bin/env python3

import argparse
import subprocess
import os
import sys


def run_command(cmd, cwd=None):
    try:
        print(f"Running: {' '.join(cmd)}")
        subprocess.run(cmd, check=True, cwd=cwd)
    except subprocess.CalledProcessError as e:
        print(f"Command failed: {' '.join(cmd)}\nError: {e}", file=sys.stderr)
        sys.exit(e.returncode)


def build(target):
    run_command(["cmake", "-B", "build"])
    if target == "all":
        run_command(["cmake", "--build", "build"])
    else:
        run_command(["cmake", "--build", "build", "--target", target])


def test(target):
    dir_path = os.path.join("build", "bin")
    if not os.path.isdir(dir_path):
        print(
            f"Test directory '{dir_path}' does not exist. Build first.", file=sys.stderr
        )
        sys.exit(1)

    if target == "all":
        files = [
            f
            for f in os.listdir(dir_path)
            if os.access(os.path.join(dir_path, f), os.X_OK)
        ]
        if not files:
            print(f"No executables found in '{dir_path}'.", file=sys.stderr)
            sys.exit(1)
        for file in files:
            file_path = os.path.join(dir_path, file)
            print(f"Running {file_path}")
            ret = subprocess.call(file_path)
            if ret != 0:
                print(f"Test {file_path} failed with exit code {ret}", file=sys.stderr)
    else:
        file_path = os.path.join(dir_path, target)
        if not os.path.isfile(file_path) or not os.access(file_path, os.X_OK):
            print(
                f"Test executable '{file_path}' not found or not executable.",
                file=sys.stderr,
            )
            sys.exit(1)
        print(f"Running {file_path}")
        ret = subprocess.call(file_path)
        if ret != 0:
            print(f"Test {file_path} failed with exit code {ret}", file=sys.stderr)
            sys.exit(ret)


def main():
    parser = argparse.ArgumentParser(description="Build and test LeetCode solutions")
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

    args = parser.parse_args()

    if args.command == "build":
        build(args.target)
    elif args.command == "test":
        test(args.target)


if __name__ == "__main__":
    main()
