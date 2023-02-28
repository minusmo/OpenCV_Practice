# see https://cmake.org/cmake/help/latest/module/FindBoost.html
set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking

# search for unit test framework
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

add_executable(calc_test_boost test.cpp)

# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(calc_test_boost ${Boost_LIBRARIES})
# link boost with code libary which is to be tested
target_link_libraries(calc_test_boost calc_library)