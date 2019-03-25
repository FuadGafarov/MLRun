#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "ImageMatcher.h"
#include <iostream>


using namespace std;
using namespace cv;


bool MatchImage(Mat inputImage, Mat templateImage, int maxLimitForMatcher) {
	cv::Mat input = inputImage;
	cv::Mat templ = templateImage;


    cv::Mat img = input;
    cv::Mat result;
    /// Create the result matrix
    int result_cols =  img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    result.create( result_cols, result_rows, CV_32FC1 );

    int match_method = CV_TM_SQDIFF;

    /// Do the Matching and Normalize
    matchTemplate( img, templ, result, match_method  );
    normalize( result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );

    /// Localizing the best match with minMaxLoc
    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
    cv::Point matchLoc;

    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );

    /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
    if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
    {
		matchLoc = minLoc; 

	}
    else
    { 
		matchLoc = maxLoc; 

	}

	if(matchLoc.x <= maxLimitForMatcher || matchLoc.y <= maxLimitForMatcher) {
		return true;
	} else {
		return false;
	}

    /// Show me what you got
    cv::rectangle( input, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar::all(0), 2, 8, 0 );
    cv::rectangle( result, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar::all(0), 2, 8, 0 );


    cv::imshow("input", input);
    cv::imshow("template", templ);

    cv::imwrite("../outputData/TemplateMatch.jpg", input);
	waitKey(0);
}
