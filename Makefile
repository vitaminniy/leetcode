all: build

BUILD_TYPE ?= Release
BUILD_DIR ?= build
CC ?= /usr/bin/cc
CXX ?= /usr/bin/c++

help: ## Print this help
help:
	@IFS=$$'\n' ; \
	help_lines=(`fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##/:/'`); \
	printf "%-20s %s\n" "target" "help" ; \
	printf "%-20s %s\n" "------" "----" ; \
	for help_line in $${help_lines[@]}; do \
		IFS=$$':' ; \
		help_split=($$help_line) ; \
		help_command=`echo $${help_split[0]} | sed -e 's/^ *//' -e 's/ *$$//'` ; \
		help_info=`echo $${help_split[2]} | sed -e 's/^ *//' -e 's/ *$$//'` ; \
		printf '\033[36m'; \
		printf "%-20s %s" $$help_command ; \
		printf '\033[0m'; \
		printf "%s\n" $$help_info; \
	done

clean: ## Delete built files
clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

cmake: ## Run cmake generator
cmake:
	cmake -B $(BUILD_DIR) -G "Unix Makefiles" \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE)      \
		-DCMAKE_C_COMPILER=$(CC)              \
		-DCMAKE_CXX_COMPILER=$(CXX)
.PHONY: cmake

clang-format: ## Format C++ code
clang-format: cmake
	cd $(BUILD_DIR) && make clang-format
.PHONY: format

build: ## Build projects
build: cmake
	cd $(BUILD_DIR) && cmake --build .
.PHONY: build

test: ## Run tests
test: build
	cd $(BUILD_DIR) && CTEST_OUTPUT_ON_FAILURE=1 make test
.PHONY: test
