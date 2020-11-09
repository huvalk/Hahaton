set(EXECUTABLES Storage.cpp)
# Make an automatic library - will be static or dynamic based on user setting
add_library(storage ${EXECUTABLES})

# We need this directory, and users of our library will need it too
target_include_directories(storage PUBLIC ../include)

# All users of this library will need at least C++11
target_compile_features(storage PUBLIC cxx_std_14)