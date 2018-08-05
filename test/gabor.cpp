#include "gabor.h"

std::vector<cv::Mat> Gabor::getFeatures(cv::Mat & inputImage)
{
	if (inputImage.channels() > 1)
	{
		cv::cvtColor(inputImage, inputImage, CV_BGR2GRAY);
	}

	int k = 1;
	int scaleSize = 5;
	int orientSize = 8;

	int R = inputImage.rows;
	int C = inputImage.cols;

	cv::Mat tar;
	std::vector<cv::Mat> G_img;

	inputImage.copyTo(tar);

	for (int v = 0; v < scaleSize; v++)
	{
		for (int u = 1; u <= orientSize; u++)
		{
			// Get gabor feature by convolving with Gabor wavelet
			cv::Mat GW = gWavelet.run(R, C, Kmax, f, u, v, Delt);
			cv::Mat chann[2], filterMat, Regabout;

			cv::split(GW, chann);
			cv::copyMakeBorder(chann[0], filterMat, 0, 0, 0, 0, cv::BORDER_CONSTANT);
			cv::filter2D(tar, Regabout, -1, filterMat);
			G_img.push_back(Regabout);

		} // end of u-loop
	} // end of v-loop

	return G_img;

} // end of function definition


void Gabor::GaborTranform(cv::Mat &inputImage, cv::Mat &outputImage, double u, double v)//u为方向0-7，v为尺度0-4
{
	if (inputImage.channels() > 1)
	{
		cv::cvtColor(inputImage, inputImage, CV_BGR2GRAY);
	}

	int R = inputImage.rows;
	int C = inputImage.cols;

	cv::Mat tar;
	cv::Mat G_img;

	inputImage.copyTo(tar);

	cv::Mat GW = gWavelet.run(R, C, Kmax, f, u + 1, v, Delt);
	cv::Mat chann[2], filterMat, Regabout;

	cv::split(GW, chann);
	cv::copyMakeBorder(chann[0], filterMat, 0, 0, 0, 0, cv::BORDER_CONSTANT);
	cv::filter2D(tar, Regabout, -1, filterMat);

	outputImage = Regabout;

}