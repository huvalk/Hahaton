#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
    Mat image;
    VideoCapture cap(0);
    cap.open("/dev/v4l/by-id/usb-046d_0825_AEDDCBD0-video-index0");
// Load Face cascade (.xml file)
//    CascadeClassifier face_cascade;
//    face_cascade.load("haarcascade_frontalface_default.xml");
    CascadeClassifier eye_cascade;
    eye_cascade.load("haarcascade_eye.xml");
//    CascadeClassifier mouth_cascade;
//    mouth_cascade.load("haarcascade_mcs_mouth.xml");

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        cap >> image;
        // Detect faces
//        std::vector<Rect> faces;
//        face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
//        // Detect mouth
//        std::vector<Rect> mouths;
//        mouth_cascade.detectMultiScale(image, mouths, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
        // Detect eye
        std::vector<Rect> eyes;
        eye_cascade.detectMultiScale(image, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

//        for (int i = 0; i < faces.size(); i++)
//        {
//            Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
//            ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
//        }
//        for (int i = 0; i < mouths.size(); i++)
//        {
//            Point center(mouths[i].x + mouths[i].width*0.5, mouths[i].y + mouths[i].height*0.5);
//            ellipse(image, center, Size(mouths[i].width*0.5, mouths[i].height*0.5), 0, 0, 360, Scalar(255, 0, 0), 4, 8, 0);
//        }
        for (int i = 0; i < eyes.size(); i++)
        {
            Point center(eyes[i].x + eyes[i].width*0.5, eyes[i].y + eyes[i].height*0.5);
            ellipse(image, center, Size(eyes[i].width*0.5, eyes[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
        }
        imshow("Detected Face", image);
        waitKey(1);

    }
#pragma clang diagnostic pop

    return 0;
}
