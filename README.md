# GoogleTest Tutorial
Set of tutorial to learn google test framework

## Connecting GoogleTest to a project
Instructions based on the following [tutorial](https://www.youtube.com/watch?v=pxJoVRfpRPE&t=461s).

1. Create submodule for a repository:
```git submodule add https://github.com/google/googletest.git external/googletest```
2. Create submodule update procedure with CMake which updates all existing submodules
3. Configure CMake

## Launching tests
```GTEST_COLOR=1 ctest --test-dir build --output-on-failure```
