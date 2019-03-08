
cmake_minimum_required(VERSION 3.10)

find_package(CGAL)
find_package( Boost 1.65.1 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
add_executable(meshgen main.cpp)
target_link_libraries(meshgen CGAL::CGAL ${Boost_LIBRARIES})