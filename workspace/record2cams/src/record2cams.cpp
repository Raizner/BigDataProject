//============================================================================
// Name        : record2cams.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;





/**
 * Rotate an image
 */
/*
void rotate(cv::Mat& src, double angle, cv::Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    cv::Point2f pt(len/2., len/2.);
    cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

    cv::warpAffine(src, dst, r, cv::Size(len, len));
}
*/
/*
int mainNotWorking(){

	VideoCapture cap = VideoCapture();
	cap.open("http://127.0.0.1:8081");
	cv::Mat image ;
	if ( cap.isOpened()){
		cap >> image;
		imshow( "Frame - Right", image );
		waitKey();
	}


	return 0;
}
*/
int main(){

    VideoCapture vcap;
    VideoCapture vcap1;
      if(!vcap.isOpened() || !vcap1.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);


   int frame_width1=   vcap1.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height1=   vcap1.get(CV_CAP_PROP_FRAME_HEIGHT);
   //VideoWriter video("test_inlab_lefat.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width,frame_height),true);
 //  VideoWriter video1("test_inlab_righat.avi",CV_FOURCC('M','J','P','G'),10, Size(frame_width1,frame_height1),true);

   for(int i = 0;; i++){

       Mat frame;
       Mat frame1;
       vcap >> frame;
       vcap1 >> frame1;
/*
       Mat tempFrame = frame;
       Mat tempFrame1 = frame1;

       cv::transpose(frame, tempFrame);
       cv::flip(tempFrame, tempFrame, 0);

       cv::transpose(tempFrame, frame);
       cv::flip(frame, frame, 0);

       cv::transpose(frame1, tempFrame1);
       cv::flip(tempFrame1, tempFrame1, 0);

       cv::transpose(tempFrame1, frame1);
       cv::flip(frame1, frame1, 0);
*/
       //rotate(frame1, 180, frame);
       //rotate(frame, 180, frame1);

      // video.write(frame);
      // video1.write(frame1);
       imwrite("../../triangulation matlab/InLab/Triangulation/right/" + to_string(i) + ".jpg",frame);
       imwrite("../../triangulation matlab/InLab/Triangulation/left/" + to_string(i) + ".jpg",frame1);

       if ( i > 100) {
    	   remove(("../../triangulation matlab/InLab/Triangulation/right/" + to_string(i-100) + ".jpg").c_str());
    	   remove(("../../triangulation matlab/InLab/Triangulation/left/" + to_string(i-100) + ".jpg").c_str());


       }
       //imshow( "Frame - Right", frame );
       //imshow( "Frame1 - Left", frame1 );
       char c = (char)waitKey(300);
       if( c == 27 ) break;

    }
  return 0;
}



