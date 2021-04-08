set(EXECUTABLES Network.cpp Vision.cpp FrontalFaceDetector.cpp)
set(CURL_LIBRARY "-lcurl")
# Make an automatic library - will be static or dynamic based on user setting
add_library(vision ${EXECUTABLES})

# We need this directory, and users of our library will need it too
target_include_directories(vision PUBLIC ../include)

find_package(CURL REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_include_directories(vision PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(vision PRIVATE ${OpenCV_LIBS} ${CURL_LIBRARIES})

# All users of this library will need at least C++11
#target_compile_features(vision PUBLIC cxx_std_14)