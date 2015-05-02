/*
 * Calibration.h
 *
 *  Created on: Nov 17, 2014
 *      Author: artyom
 */

#ifndef CALIBRATION_H_
#define CALIBRATION_H_

#include <opencv2/opencv.hpp>

#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



using namespace cv;
using namespace std;

class Calibration {


public:
	Mat globalQ, globalT;
	Calibration();
	vector<Mat> Calibrate(const string& filename, int boardHeight, int boardWidth, Mat* T, Mat* Q);
	vector<Mat> StereoCalib(const vector<string>& , Size , bool , bool );
	bool readStringList( const string& filename, vector<string>& l );
};

#endif /* CALIBRATION_H_ */
