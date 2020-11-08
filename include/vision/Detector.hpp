//
// Created by huvalk on 06.11.2020.
//

#pragma once

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <string>
#include <set>

namespace Vision {
    class Detector {
    public:
        virtual std::vector<cv::Rect> detectObject(const cv::Mat& image) = 0;

        virtual ~Detector() = default;;
    };
}