/*
 * Triangulate.h
 *
 *  Created on: Nov 17, 2014
 *      Author: artyom
 */

#ifndef TRIANGULATE_H_
#define TRIANGULATE_H_

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

using namespace std;
using namespace cv;

class Triangulate {
public:
	Triangulate();

	double* triangulate(Mat cam0P, Mat cam1P, float cam0x, float cam0y, float cam1x, float cam1y, Mat T, Mat Q, double*);
};

#endif /* TRIANGULATE_H_ */
