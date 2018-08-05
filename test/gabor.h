#ifndef GABORFEATURE_H
#define GABORFEATURE_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "gaborwavelet.h"


class Gabor
{
public:
	std::vector<cv::Mat> getFeatures(cv::Mat & inputImage);//得到全尺度全方向的特征
	void GaborTranform(cv::Mat &inputImage, cv::Mat &outputImage, double u, double v);//u为方向0-7，v为尺度0-4，Gabor实部变换

private:
	double Kmax = PI ;// 原值PI / 2
	double f = std::sqrt(2);
	double Delt = 6 * PI;//原值2*PI
	
	GaborWavelet gWavelet;
};


#endif 