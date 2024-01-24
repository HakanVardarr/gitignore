cmake_minimum_required(VERSION 3.27)

project(gitignore)

# Find libraries
find_package(CURL REQUIRED)

add_executable(gitignore main.cpp)
target_link_libraries(gitignore PRIVATE ${CURL_LIBRARIES})
target_include_directories(gitignore PRIVATE ${CURL_INCLUDE_DIRS})


