cmake_minimum_required (VERSION 2.6)
project (StockMarketSimulator CXX)
# The version number.
set (StockMarketSimulator_VERSION_MAJOR 1)
set (StockMarketSimulator_VERSION_MINOR 0)

# include the cmake modules directory
set(CMAKE_MODULE_PATH ${program_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# add subdirectory
add_subdirectory(src)