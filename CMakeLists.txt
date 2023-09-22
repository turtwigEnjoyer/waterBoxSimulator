cmake_minimum_required(VERSION 3.26)

project(fluid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

set(CMAKE_CXX_FLAGS_RELEASE "−march=native")

add_executable(${PROJECT_NAME} fluid.cpp) ## BUILDS IN DEBUG BY DEFAULT!! IMPORTANT LATER
install(TARGETS ${PROJECT_NAME} DESTINATION bin)


add_compile_options(−Wall −Wextra −Werror −pedantic −pedantic−errors)