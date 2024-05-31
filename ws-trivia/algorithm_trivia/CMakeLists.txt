cmake_minimum_required(VERSION 3.10)

project(algorithm_trivia)

add_test(NAME algorithm_trivia COMMAND algorith_trivia --exe $<TARGETFILE:myexe>)

include_directories(cute/ src/)

add_executable(algorithm_trivia
  src/Test.cpp				src/find_algorithms.cpp			src/numeric_algorithms.cpp		src/remove_unique_rotate_algorithms.cpp	src/sorted_sequence_algorithms.cpp
  src/copy_and_replace_algorithms.cpp	src/heap_algorithms.cpp			src/partition_algorithms.cpp		src/set_algorithms.cpp
  src/fill_and_generate_algorithms.cpp	src/min_max_algorithms.cpp		src/property_checking_algorithms.cpp	src/sort_algorithms.cpp
    )
    
target_compile_features(algorithm_trivia PRIVATE cxx_std_17)

