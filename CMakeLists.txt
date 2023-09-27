cmake_minimum_required(VERSION 3.26)
project(fluid LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

## BUILDS IN DEBUG BY DEFAULT!! IMPORTANT LATER
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors -ggdb  -g)
## TO REMOVE DEBUG REPLACE BY:
#add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

set(CMAKE_CXX_FLAGS_RELEASE "−march=native")
##
add_library(lib1 progargs.cpp particle.cpp grid.cpp block.cpp)
add_executable(${PROJECT_NAME} fluid.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE lib1)
##target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
#install(TARGETS ${PROJECT_NAME} DESTINATION bin)

