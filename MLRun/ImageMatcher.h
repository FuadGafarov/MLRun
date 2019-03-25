#ifndef IMAGEMATCHER_H
#define IMAGEMATCHER_H


#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"



using namespace cv;

bool MatchImage(Mat inputImage, Mat templateImage, int maxLimitForMatcher);


#endif