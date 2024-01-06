all: build

BUILD_TYPE ?= Release
BUILD_DIR ?= build
CC ?= /usr/bin/cc
CXX ?= /usr/bin/c++

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

cmake:
	cmake -B $(BUILD_DIR) -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE)      \
		-DCMAKE_C_COMPILER=$(CC)              \
		-DCMAKE_CXX_COMPILER=$(CXX)
.PHONY: cmake

clang-format: cmake
	cd $(BUILD_DIR) && make clang-format
.PHONY: format

build: cmake
	cd $(BUILD_DIR) && cmake --build .
.PHONY: build

test: build
	cd $(BUILD_DIR) && CTEST_OUTPUT_ON_FAILURE=1 make test
.PHONY: test
