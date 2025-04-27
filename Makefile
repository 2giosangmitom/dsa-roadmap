generate:
	cmake -B build

build: generate
	cmake --build build

test: build
	ctest --test-dir build

clean:
	rm -rf build/

.PHONY: generate build test clean
