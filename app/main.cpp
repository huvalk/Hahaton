#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vision/Vision.hpp>

#define WEBCAM_PATH "/dev/v4l/by-id/usb-046d_0825_AEDDCBD0-video-index0"

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);
    Mat image;
//    cap.open("/dev/v4l/by-id/usb-046d_0825_AEDDCBD0-video-index0");
    Vision::Vision vision;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        try {
            cap >> image;

            auto faces = vision.performDetection(image);

            for (const auto& face: faces) {
                Point center(face.x + face.width*0.5, face.y + face.height*0.5);
                ellipse(image, center, Size(face.width*0.5, face.height*0.5),
                        0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
            }
            imshow("Detected Face", image);
        } catch (const cv::Exception& e) {
            std::cout << "cv exception: " << e.msg << std::endl;
        } catch (...) {
            std::cout << "Fatal exception" << std::endl;
        }

        waitKey(1);
    }
#pragma clang diagnostic pop
#pragma clang diagnostic pop

    return 0;
}
