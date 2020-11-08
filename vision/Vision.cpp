//
// Created by huvalk on 06.11.2020.
//

#include "vision/Vision.hpp"
#include "vision/FrontalFaceDetector.hpp"

#define FRONTAL_FACE "../../haar_cascades/haarcascade_frontalface_default.xml"
#define FRONTAL_EYE "../../haar_cascades/haarcascade_eye.xml"

namespace Vision {

    Vision::Vision() noexcept
        : m_face_detectors() {
        m_face_detectors.emplace_back(std::make_unique<FrontalFaceDetector>(FRONTAL_EYE, FRONTAL_FACE));
    }

    void Vision::setSource(const std::string& source_path) {

    }

    std::vector<cv::Rect> Vision::performDetection(const cv::Mat& image) {
        std::vector<cv::Rect> result_faces{};

        for (const auto& face_detector: m_face_detectors) {
            auto faces = face_detector->detectObject(image);

            for (const auto& face: faces) {
                result_faces.push_back(face);
                // TODO Выполнять проверку на пересечение
            }
        }
        return result_faces;
    }
}