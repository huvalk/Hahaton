//
// Created by huvalk on 06.11.2020.
//

#pragma once

#include "Detector.hpp"
#include <string>

namespace Vision {
    class Vision {
    public:
        explicit Vision() noexcept;
        void setSource(const std::string& source_path);
        std::vector<cv::Rect> performDetection(const cv::Mat& image);

    private:
        std::vector<std::unique_ptr<Detector>> m_face_detectors;
    };
}