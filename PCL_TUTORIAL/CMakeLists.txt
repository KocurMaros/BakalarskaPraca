cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(example)

# set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(PCL 1.2 REQUIRED)
find_package(Boost 1.40 COMPONENTS thread    REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


add_executable(example example.cpp)
target_link_libraries(example ${PCL_LIBRARIES} ${Boost_LIBRARIES})

