cmake_minimum_required(VERSION 3.10)

project(base_lib)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug)
set(CMAKE_CXX_STANDARD 17)

# Find FFmpeg library
# find_package(FFmpeg REQUIRED)
include_directories(src)
file(GLOB SOURCES "src/*/*.cpp")
# Add executable target
add_executable(${PROJECT_NAME} ./main.cpp ${SOURCES})

# Link FFmpeg libraries
target_link_libraries(${PROJECT_NAME} ${FFMPEG_LIBRARIES})
install(TARGETS ${PROJECT_NAME} DESTINATION ./build/Debug)