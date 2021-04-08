#pragma once
#include <string>

namespace Network {
    class Sender {
    public:
        static bool sendCameraInfo(const int &cameraId, const int &people);
    };
};


