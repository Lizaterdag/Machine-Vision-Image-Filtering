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

int DotDetection9() {

    string path = R"(\Users\Liza\Studie_Liza\Jaar4\Machine_Vision\dice\*.png)";

    vector<string> images;
    /* Find images in system folder */
    cv::glob(path, images);

    for (size_t i = 0; i < images.size(); i++) {

        /* read the images greyscaled*/
        Mat im = imread(images[i], IMREAD_GRAYSCALE);

        /* parameters for the detector*/
        SimpleBlobDetector::Params params;
        params.filterByArea = true;
        params.minArea = 1500;

        /* detector with the filter*/
        cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);

        /* blob detection*/
        std::vector<KeyPoint> keypoint;
        detector->detect(im, keypoint);

        printf("Image %s \n", &images[i][0]);
        printf("#dots: %d \n", size(keypoint));

    }
    return 0;
}
