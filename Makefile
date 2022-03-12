all: build

BUILD_TYPE ?= Release
BUILD_DIR ?= build

init:
	@git submodule update --init --recursive
.PHONY: init

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

cmake:
	cmake -B $(BUILD_DIR) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
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
