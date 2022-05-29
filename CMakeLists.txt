cmake_minimum_required(VERSION 3.0.0)

project(liboinput)

if(WIN32)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

list(APPEND oinput_src_files
    ./include/oinput/Input.h
    ./src/Input.cpp
    ./include/oinput/GamePad.h
    ./src/GamePad.cpp
    ./include/oinput/Joystick.h
    ./src/Joystick.cpp
    ./src/Utils.h
)

if (WIN32)
    list(APPEND oinput_platform_src_files
        ./src/InputWin32.h
        ./src/InputWin32.cpp
        ./src/GamePadWin32.h
        ./src/GamePadWin32.cpp
        ./src/JoystickWin32.h
        ./src/JoystickWin32.cpp
        ./src/UtilsWin32.cpp
    )
endif()

if(WIN32)
    list(APPEND oinput_libs dxguid xinput dinput8)
endif()

add_library(${PROJECT_NAME} STATIC ${oinput_src_files} ${oinput_platform_src_files})
target_include_directories(${PROJECT_NAME} PUBLIC ./include ./src)
target_link_libraries(${PROJECT_NAME} PUBLIC ${oinput_libs})
