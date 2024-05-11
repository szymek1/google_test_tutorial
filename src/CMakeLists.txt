if(BUILD_TESTING)
    set(SRC_FILES
        account.cpp
        atm.cpp
    )
endif()

if(PRODUCTION)
    set(SRC_FILES
        account.cpp
        atm.cpp
        my_bank_server.cpp
    )
endif()

add_library(tutorial_lib ${SRC_FILES})

target_include_directories(tutorial_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)