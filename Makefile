all: build

BUILD_TYPE ?= Release

build_dir := $(if $(BUILD_DIR),$(BUILD_DIR),build)
build_type := $(if $(BUILD_TYPE),$(BUILD_TYPE),Release)

clean:
	rm -rf $(build_dir)
.PHONY: clean

cmake:
	cmake -E make_directory $(build_dir)
	cmake -B $(build_dir) -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$(build_type)
.PHONY: cmake

clang-format: cmake
	cd $(build_dir) && make clang-format
.PHONY: format

build: cmake
	cd $(build_dir) && cmake --build .
.PHONY: build

test: build
	cd $(build_dir) && CTEST_OUTPUT_ON_FAILURE=1 make test
.PHONY: test
