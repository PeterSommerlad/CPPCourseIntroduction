cmake_minimum_required(VERSION 3.5)

project(hellogtest)

add_executable(the_executable
    sayhello.cpp
    main.cpp)

target_link_libraries(the_executable
  gtestd gtest_maind )
