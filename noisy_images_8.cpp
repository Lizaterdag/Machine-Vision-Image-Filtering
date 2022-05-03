//
// Created by Liza Darwesh on 21/04/2022.
//

#include<cstdlib>
#include<iostream>
#include<filesystem>
#include<opencv2/opencv.hpp>
#include<cstring>
#include<vector>

using namespace cv;
using namespace std;

int NoiseReduction8(int argc, char** argv) {

    string path = R"(\Users\Liza\Studie_Liza\Jaar4\Machine_Vision\noice\*.bmp)";
    vector<string> images;

    /* Find images in system folder */
    cv::glob(path, images);

    for (size_t i = 0; i < images.size(); i++) {
        Mat distance;

        /* Read grayscaled image*/
        Mat image = imread(images[i], IMREAD_GRAYSCALE);

        /* remove noise from the images*/
        fastNlMeansDenoising(image, distance, 7, 21);

        /* Show the images*/
        imshow("before", image);
        imshow("after", distance);
    }
    return 0;
}

