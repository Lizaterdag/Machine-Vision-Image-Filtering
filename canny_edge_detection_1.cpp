//
// Created by Liza Darwesh on 19/04/2022.
//

#include<cstdlib>
#include<iostream>
#include<filesystem>
#include<opencv2/opencv.hpp>
#include<dirent.h>
#include<cstring>
#include<vector>
#include<opencl-c-base.h>

using namespace cv;
using namespace std;

int CannyEdgeDetection1(int argc, char** argv) {

    string dir = R"(\Users\Liza\Studie_Liza\Jaar4\Machine_Vision\images\*.jpg)";
    vector<string> images;

    /* Find images in system folder */
    cv::glob(dir, images);

    for (auto & image : images) {

        Mat img = imread(images[i], IMREAD_COLOR);
        Scalar color;
        Mat distance;
        int cross = 0;

        /* Canny Edge Detection*/
        Canny(img, distance, 50, 200, 3);

        /* Check for crossing, if line found add 1 to cross */
        int y = distance.cols - 20;
        for (int x = 0; x < distance.rows; x++) {
            if ((int)distance.at<uchar>(x, y) == 255) {
                cross++;
            }
        }
        /* Image output*/
        printf("Image: %s\n", &image[0]);
        if (cross >= 6){
            printf("connected");
        } else printf("not connected");
    }
    return 0;
}