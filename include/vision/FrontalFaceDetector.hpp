//
// Created by huvalk on 06.11.2020.
//

#pragma once

#include "Detector.hpp"

namespace Vision {
    class FrontalFaceDetector final: public Detector {
    public:
        explicit FrontalFaceDetector(const std::string& eye_cascade, const std::string& face_cascade) noexcept;
        FrontalFaceDetector() = delete;
        ~FrontalFaceDetector() override = default;

        std::vector<cv::Rect> detectObject(const cv::Mat& image) override;

    private:
        cv::CascadeClassifier m_face_classifier;
        cv::CascadeClassifier m_eye_classifier;
    };
}


