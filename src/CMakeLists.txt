# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable called helloworld_SOURCES containing all .cpp files:
set(program_SOURCES main.cpp)

# Set up Boost libraries
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.66.0 REQUIRED COMPONENTS program_options)

# If boost is found, compile
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  # Create an executable file called main from sources:
  add_executable(main ${program_SOURCES})
  # Link the boost libraries to the program
  target_link_libraries(main ${Boost_LIBRARIES})
endif()
