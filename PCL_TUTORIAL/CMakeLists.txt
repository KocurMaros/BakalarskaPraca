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


add_executable(cylinder cylinder.cpp)
add_executable(make_pcd save_to_pcd.cpp)
add_executable(example example.cpp)
add_executable(sphere sphere.cpp)
add_executable(alignment alignment.cpp)

target_link_libraries(cylinder ${PCL_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(make_pcd ${PCL_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(example ${PCL_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(sphere ${PCL_LIBRARIES} ${Boost_LIBRARIES})
target_link_libraries(alignment ${PCL_LIBRARIES} ${Boost_LIBRARIES})