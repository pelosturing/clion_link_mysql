cmake_minimum_required(VERSION 3.25)
project(testenv)
set(CMAKE_CXX_STANDARD 17)

# mysql include&lib dictionary
set(INC_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\include)
SET(LINK_DIR C:\\Program\ Files\\MySQL\\MySQL\ Server\ 8.0\\lib)

include_directories(${INC_DIR})

link_directories(${LINK_DIR})
link_libraries(libmysql)


add_executable(testenv main.cpp AuthorManager.cpp AuthorManager.h)
target_link_libraries(testenv libmysql)
