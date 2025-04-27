generate:
	cmake -B build

build: generate
	cmake --build build

test:
	ctest --test-dir build

.PHONY: generate build test
