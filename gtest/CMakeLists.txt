cmake_minimum_required(VERSION 3.16)
project(gtest_test)
set(CMAKE_CXX_STANDARD 17)
# 添加子目录
add_subdirectory(googletest)
# 添加可执行文件
add_executable(gtest_test gtest_test.cpp)
# 如果没有在测试中写main函数，则需要链接gtest_main
target_link_libraries(gtest_test GTest::gtest_main GTest::gtest)
