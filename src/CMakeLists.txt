set(EXECUTABLES vision.cpp)
# Make an automatic library - will be static or dynamic based on user setting
add_library(vision ${EXECUTABLES})

# We need this directory, and users of our library will need it too
target_include_directories(vision PUBLIC ../include)

find_package(OpenCV REQUIRED)
target_include_directories(vision PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(vision PRIVATE ${OpenCV_LIBS})

# All users of this library will need at least C++11
target_compile_features(vision PUBLIC cxx_std_17)