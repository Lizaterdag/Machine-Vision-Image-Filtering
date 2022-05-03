//
// Created by Liza Darwesh on 19/04/2022.
//

#include<cstdlib>
#include<iostream>
#include<filesystem>
#include<opencv2/opencv.hpp>
#include<cstring>
#include<vector>
#include<opencl-c-base.h>

using namespace cv;
using namespace std;

int CannyEdgeDetection3() {

    string path = R"(\Users\Liza\Studie_Liza\Jaar4\Machine_Vision\screws\*.bmp)";
    vector<string> screws;

    /* Find images in system folder */
    cv::glob(path, screws);

    // for each image
    for (auto & screw : screws) {
        Mat img = imread(screws[i], IMREAD_COLOR);

        Scalar color;
        Mat distance;
        int cross = 0;

        // Canny edge detect
        Canny(img, distance, 255, 255, 3);

        /* Check for screws if line found, add 1 to crossing*/
        int x = distance.rows - 32;
        for (int y = 0; y < distance.cols; y++) {
            if ((int)distance.at<uchar>(x, y) == 255) {
                cross++;
            }
        }

        printf("Screws %s\n", &screw[0]);
        /* If two lines cross a screw, they are connected*/
        if (2 <= cross) {
            printf("connected");
       } else printf("not connected");
    }
    return 0;
}
