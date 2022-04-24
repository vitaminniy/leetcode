#!/usr/bin/env python3

import argparse
import os

CMAKELISTS_CONTENT = """
add_executable(${PROJECT_NAME})

file(GLOB SOURCES *.cpp)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Werror
        -Wextra
        -Wpedantic
        -Wreturn-type
)

include(GoogleTest)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GTest::gtest
        GTest::gtest_main
)

enable_testing()
gtest_discover_tests(${PROJECT_NAME})
"""


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument("task")
    parser.add_argument(
        "-n",
        "--dry-run",
        dest="dry_run",
        action="store_const",
        const=True,
        default=False,
    )
    args = parser.parse_args()

    task = args.task
    dry_run = args.dry_run

    path = os.getcwd()

    head, tail = os.path.split(path)
    if tail == "scripts":
        path = head

    src_dir = os.path.join(path, "src")
    task_dir = os.path.join(src_dir, task)
    src_cmakelists = os.path.join(src_dir, "CMakeLists.txt")
    task_cmakelists = os.path.join(task_dir, "CMakeLists.txt")

    if dry_run:
        msg = f"dir: {task_dir} would be created\n"
        msg += f"add_subdirectory({task}) would be appended "
        msg += f"to {src_cmakelists}\n"
        msg += f"{task_cmakelists} would be created\n"

        print(msg)
        return

    os.makedirs(task_dir, mode=511, exist_ok=True)

    # prepend task
    with open(src_cmakelists, "r+") as f:
        content = f.read()
        f.seek(0, 0)
        f.write(f"add_subdirectory({task})\n")
        f.write(content)

    with open(task_cmakelists, "w") as f:
        f.write(f"project({task} LANGUAGES CXX)\n")
        f.write(CMAKELISTS_CONTENT)


if __name__ == "__main__":
    main()
