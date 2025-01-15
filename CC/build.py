import os
import subprocess
import glob

# Directories
LIB_DIR = "lib"
TEST_DIR = "tests"
BUILD_DIR = "build"

# Compiler and flags
CXX = "clang++"
CXX_FLAGS = "-std=c++23 -Wall -Wextra"
GTEST_FLAGS = f"-I{os.environ.get('GTEST_DEV')} -lgtest -lgtest_main"


# Ensure the build directory exists
def create_dir():
    if not os.path.exists(BUILD_DIR):
        os.makedirs(BUILD_DIR)


# Find all test files
def get_test_files():
    test_files = []
    test_files.extend(glob.glob(os.path.join(LIB_DIR, "*_test.cc")))
    test_files.extend(glob.glob(os.path.join(TEST_DIR, "*_test.cc")))
    return test_files


# Find all library files excluding _test.cc files
def get_lib_files():
    lib_files = glob.glob(os.path.join(LIB_DIR, "*.cc"))
    return [f for f in lib_files if not f.endswith("_test.cc")]


# Compile the library files
def build_lib():
    lib_files = get_lib_files()
    for file in lib_files:
        output_file = os.path.join(
            BUILD_DIR, os.path.basename(file).replace(".cc", ".o")
        )
        print(f"Compiling {file} -> {output_file}")
        subprocess.run(
            f"{CXX} {CXX_FLAGS} -c {file} -o {output_file}", shell=True, check=True
        )


# Compile and build a specific test file
def build_test(file):
    test_name = os.path.basename(file).replace(".cc", "")
    output_file = os.path.join(BUILD_DIR, test_name)

    # Check if the test file includes "linked_list.hpp" to link with the library
    with open(file, "r") as f:
        includes_linked_list = "ListNode" in f.read()

    if includes_linked_list:
        print(f"Compiling {file} with linked_list.o -> {output_file}")
        subprocess.run(
            f"{CXX} {CXX_FLAGS} {GTEST_FLAGS} {os.path.join(BUILD_DIR, 'linked_list.o')} {file} -o {output_file}",
            shell=True,
            check=True,
        )
    else:
        print(f"Compiling {file} -> {output_file}")
        subprocess.run(
            f"{CXX} {CXX_FLAGS} {GTEST_FLAGS} {file} -o {output_file}",
            shell=True,
            check=True,
        )


# Build all tests
def build_all():
    create_dir()
    build_lib()

    test_files = get_test_files()
    for file in test_files:
        build_test(file)


# Run all tests
def run_all():
    executables = glob.glob(os.path.join(BUILD_DIR, "*"))
    for file in executables:
        if not file.endswith(".o"):
            subprocess.run(file, check=True)


# Clean build directory
def clean():
    if os.path.exists(BUILD_DIR):
        print(f"Cleaning {BUILD_DIR}")
        subprocess.run(f"rm -rf {BUILD_DIR}", shell=True, check=True)


# Command-line arguments handling
if __name__ == "__main__":
    import sys

    args = sys.argv[1:]

    if "build-all" in args:
        build_all()
    elif "build-test" in args:
        try:
            test_file = args[args.index("build-test") + 1]
            build_test(test_file)
        except IndexError:
            print("Usage: python build.py build-test <test_file_path>")
            sys.exit(1)
    elif "clean" in args:
        clean()
    elif "build-lib" in args:
        build_lib()
    elif "run-all" in args:
        run_all()
    else:
        print("Usage: python build.py <build-all|build-test|build-lib|run-all|clean>")
        sys.exit(1)
