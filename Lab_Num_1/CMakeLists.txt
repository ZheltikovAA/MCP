cmake_minimum_required(VERSION 3.20)
project(Lab_1)

set(CMAKE_CXX_STANDARD 23)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( anyExecutable main.cpp )

TARGET_LINK_LIBRARIES( anyExecutable LINK_PUBLIC ${Boost_LIBRARIES} )

add_executable(Lab_1 main.cpp matrix_solution.cpp matrix_solution.h Test.cpp Test.h)
