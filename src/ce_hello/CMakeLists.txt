cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(hellotest)

include_directories(cute/ hellolib/ )

add_executable(hellotest # name must be put in the field top of tree view
  hellotest.cpp			 # change this to hellomain.cpp to run program 
                         # and switch hellotest.cpp with hellomain.cpp
  hellolib/sayhello.cpp
    )
    
