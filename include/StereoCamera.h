#ifndef STEREO_CAMERA_H
#define STEREO_CAMERA_H

#include <opencv2/opencv.hpp>

#if USE_ZED_SDK
#   include <zed/Camera.hpp>
#endif

class StereoCamera {
public:
    StereoCamera();
    ~StereoCamera() = default;
    int getHeight();
    int getWidth();
    cv::Mat &getImageLeft();
    cv::Mat &getImageRight();
    cv::Mat &getDepthMap();
    bool read();
    void calibrate();
private:
#if USE_ZED_SDK
    sl::zed::Camera zed;
#else
    cv::VideoCapture cap;
    cv::Mat side_by_side;
    int height;
    int width;
    cv::Mat image_left;
    cv::Mat image_right;
    cv::Mat depth_map;
#endif
};

#endif
