# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##########
# Modern #
##########

# Create a variable called modern_sources containing all the .cpp files for this program
set(modern_SOURCES modern.cpp)

# Set up Boost libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0 REQUIRED COMPONENTS program_options)

# If boost is found, compile
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  # Create an executable file called main from sources:
  add_executable(modern ${modern_SOURCES})
  # Link the boost libraries to the program
  target_link_libraries(modern ${Boost_LIBRARIES})
else()
  message(WARNING "Could not find Boost. Skipping modern.cpp")
endif()

# Set variable called linear_sources containing all the cpp files for the linear program
set(linear_SOURCES linear.cpp)

# set up eigen libraries
list(APPEND CMAKE_MODULE_PATH ${linear_SOURCE_DIR}/cmake_modules)

find_package(Eigen3 REQUIRED)
include_directories(${linear_SOURCE_DIR} ${EIGEN3_INCLUDE_DIR})

add_executable(linear ${linear_SOURCES})
