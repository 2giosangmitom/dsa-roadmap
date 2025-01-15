import { existsSync, mkdirSync, readdirSync, readFileSync, rmSync } from "fs";
import { join, basename } from "path";
import { execSync } from "child_process";

// Directories
const LIB_DIR = "lib";
const TEST_DIR = "tests";
const BUILD_DIR = "build";

// Compiler and flags
const CXX = "clang++";
const CXX_FLAGS = "-std=c++23 -Wall -Wextra";
const GTEST_FLAGS = `-I${process.env.GTEST_DEV} -lgtest -lgtest_main`;

// Ensure the build directory exists
function createDir() {
  if (!existsSync(BUILD_DIR)) {
    mkdirSync(BUILD_DIR);
  }
}

// Find all test files
function getTestFiles() {
  const testFiles = [
    ...readdirSync(LIB_DIR)
      .filter((file) => file.endsWith("_test.cc"))
      .map((file) => join(LIB_DIR, file)),
    ...readdirSync(TEST_DIR)
      .filter((file) => file.endsWith("_test.cc"))
      .map((file) => join(TEST_DIR, file)),
  ];
  return testFiles;
}

// Find all library files excluding _test.cc files
function getLibFiles() {
  const libFiles = readdirSync(LIB_DIR)
    .filter((file) => file.endsWith(".cc") && !file.endsWith("_test.cc"))
    .map((file) => join(LIB_DIR, file));
  return libFiles;
}

// Compile the library files
function buildLib() {
  const libFiles = getLibFiles();
  libFiles.forEach((file) => {
    const outputFile = join(BUILD_DIR, basename(file, ".cc") + ".o");
    console.log(`Compiling ${file} -> ${outputFile}`);
    execSync(`${CXX} ${CXX_FLAGS} -c ${file} -o ${outputFile}`);
  });
}

// Compile and build a specific test file
function buildTest(file) {
  const testName = basename(file, ".cc");
  const outputFile = join(BUILD_DIR, testName);

  // Check if the test file includes "linked_list.hpp" to link with the library
  const includesLinkedList = readFileSync(file, "utf8").includes("ListNode");

  if (includesLinkedList) {
    console.log(`Compiling ${file} with linked_list.o -> ${outputFile}`);
    execSync(
      `${CXX} ${CXX_FLAGS} ${GTEST_FLAGS} ${join(
        BUILD_DIR,
        "linked_list.o"
      )} ${file} -o ${outputFile}`
    );
  } else {
    console.log(`Compiling ${file} -> ${outputFile}`);
    execSync(`${CXX} ${CXX_FLAGS} ${GTEST_FLAGS} ${file} -o ${outputFile}`);
  }
}

// Build all tests
function buildAll() {
  createDir();
  buildLib();

  const testFiles = getTestFiles();
  testFiles.forEach((file) => {
    buildTest(file);
  });
}

// Run all tests
function runAll() {
  const executables = [
    ...readdirSync(BUILD_DIR)
      .filter((file) => !file.endsWith(".o"))
      .map((file) => join(BUILD_DIR, file)),
  ];

  for (const file of executables) {
    execSync(file, { stdio: "inherit" });
  }
}

// Clean build directory
function clean() {
  if (existsSync(BUILD_DIR)) {
    console.log(`Cleaning ${BUILD_DIR}`);
    rmSync(BUILD_DIR, { recursive: true, force: true });
  }
}

// Command-line arguments handling
const args = process.argv.slice(2);
if (args.includes("build-all")) {
  buildAll();
} else if (args.includes("build-test")) {
  const testFile = args[args.indexOf("build-test") + 1];
  if (!testFile) {
    console.error("Usage: node build.js build-test <test_file_path>");
    process.exit(1);
  }
  buildTest(testFile);
} else if (args.includes("clean")) {
  clean();
} else if (args.includes("build-lib")) {
  buildLib();
} else if (args.includes("run-all")) {
  runAll();
} else {
  console.error(
    "Usage: node build.js <build-all|build-test|build-lib|run-all|clean>"
  );
  process.exit(1);
}
