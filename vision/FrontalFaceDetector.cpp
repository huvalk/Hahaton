//
// Created by huvalk on 06.11.2020.
//

#include <opencv2/core/types.hpp>
#include <opencv2/objdetect.hpp>
#include "vision/FrontalFaceDetector.hpp"
#include <iostream>

namespace Vision {
    FrontalFaceDetector::FrontalFaceDetector(const std::string& eye_cascade, const std::string& face_cascade) noexcept
            : m_eye_classifier(eye_cascade), m_face_classifier(face_cascade){
    }

    std::vector<cv::Rect> FrontalFaceDetector::detectObject(const cv::Mat& image) {
        std::vector<cv::Rect> eyes;
        m_eye_classifier.detectMultiScale(image, eyes, 1.1, 2,
                                      0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
        std::vector<cv::Rect> faces;
        m_face_classifier.detectMultiScale(image, faces, 1.1, 2,
                                          0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        std::vector<cv::Rect> result{};
        for (const auto& face: faces) {
            bool intersects = false;
            bool comparable = false;

            for (const auto& eye: eyes) {
                intersects = (face & eye).area() > 0;

                if (intersects) {
                    break;
                }
            }

            if (intersects) {
                result.push_back(face);
            }
        }

        return result;
    }
}