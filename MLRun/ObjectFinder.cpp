#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "ImageMatcher.h"
#include <iostream>


using namespace std;
using namespace cv;

Mat findObjects(Mat input) {
	  int edgeThresh = 1;
	  int lowThreshold=50;
	  int const max_lowThreshold = 100;
	  int ratio = 3;
	  int kernel_size = 3;
	  RNG rng(12345);

	  vector<vector<Point> > contours;
	  vector<Vec4i> hierarchy;
	  vector<vector<Point> > contours_poly( contours.size() );
	    vector<Rect> boundRect( contours.size() );
  vector<Point2f>center( contours.size() );
  vector<float>radius( contours.size() );
	  Mat canny;
	  	 /*
	Rect roi = Rect(0, input.rows/2, input.cols, input.rows/2);
    Mat ROI_image = input(roi);
	Canny(ROI_image, canny, lowThreshold, lowThreshold*ratio, kernel_size);
	findContours( canny, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	

	 for( int i = 0; i< contours.size(); i++ ) {
		 approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
       boundRect[i] = boundingRect( Mat(contours_poly[i]) );
       minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
     }

	   Mat drawing = Mat::zeros( canny.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( 255,255,255 );
       rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
     }
	 */
	  vector<vector<Point>> a;
	//  a[0][0] == 0;
	//  approxPolyDP();
	imshow("", input);
	return input;
}












