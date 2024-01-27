cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

# For Windows (TODO: Just use the exteral_include in future)
# Use your own cmake_toolchain (vcpkg) or else this will not work
# set(CMAKE_TOOLCHAIN_FILE "C:/Users/hakov/Documents/Programming/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(gitignore)

include_directories(src) 
aux_source_directory(src SOURCES)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

find_package(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})

