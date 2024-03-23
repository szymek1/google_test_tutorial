# GoogleTest Tutorial
Set of tutorial to learn google test framework

## Connecting GoogleTest to a project
Instructions based on the following [tutorial](https://www.youtube.com/watch?v=pxJoVRfpRPE&t=461s).

1. Create submodule for a repository:
```git submodule add https://github.com/google/googletest.git external/googletest```
2. Create submodule update procedure with CMake which updates all existing submodules check: ```cmake/UpdateSubmodules.cmake```
3. Configure CMake for main compilation and ```/src``` and ```/tests``` directories

## Launching tests
Keep in mind that CTest flag ```BUILD_TESTING``` has to be ON (it is by default) in order to compile tests. After compilation with ```make``` run the following command: 
```GTEST_COLOR=1 ctest --test-dir build --output-on-failure```

In order to compile the project without tests disable ```BUILD_TESTING``` and instead include ```main.cpp``` or whatever else.
