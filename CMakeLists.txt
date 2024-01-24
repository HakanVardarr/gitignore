cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)

# Use your own cmake_toolchain (vcpkg) or else this will not work
set(CMAKE_TOOLCHAIN_FILE "C:/Users/hakov/Documents/Programming/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(gitignore)
add_executable(${PROJECT_NAME} main.cpp)

find_package(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})

