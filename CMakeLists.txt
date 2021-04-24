cmake_minimum_required(VERSION 3.0.0)
project(Proiect_SD VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Proiect_SD main.cc node.cc rb_node.cc binary_tree.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
