#include <cstdlib>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vision/Vision.hpp>
#include <vision/Network.hpp>

#define WEBCAM_PATH "/dev/v4l/by-id/usb-046d_0825_AEDDCBD0-video-index1"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    auto cameraString = std::getenv("CAMERA_ID");
    auto cameraID = std::stoi(cameraString);
    VideoCapture cap(WEBCAM_PATH);
    Mat image;
    if (argc > 1) {
        cap.open(argv[1]);
    }
//    while (!cap.isOpened()) {
//        std::cout << "Unable to reach camera";
//        return 1;
//    }
    Vision::Vision vision;

#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        try {
//            cap >> image;
//            if(image.empty()) {
//                std::cout << "Empty image";
//                break;
//            }
//
//            auto faces = vision.performDetection(image);
            auto faces = 15;
            Network::Sender::sendCameraInfo(cameraID, faces);
        } catch (const cv::Exception& e) {
            std::cout << "cv exception: " << e.msg << std::endl;
        } catch (...) {
            std::cout << "Fatal exception" << std::endl;
        }

        waitKey(1);
    }
#pragma clang diagnostic pop

    return 0;
}
