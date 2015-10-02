#pragma once

#ifndef OPENCV_LIB
#define OPENCV_LIB

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

#endif

class CAlgorithm
{
public:
	CAlgorithm(void);
	~CAlgorithm(void);

	//Display Ã¢¼³Á¤
	CDC *m_pOriginalDC, *m_pProcess1DC, *m_pProcess2DC, *m_pProcess3DC;
	void SetResultDC(CDC *pOriginalDC, CDC *pProcess1DC, CDC *pProcess2DC, CDC *pProcess3DC);

	//Image Load
	void OCVLoadImage(void);
	void OCVGrayImage(void);
	void OCVThreshold(void);
	void OCVSplitImage(void);
	void OCVHistogram(void);
	void OCVColorExtraction(void);
	void OCVResize(void);

	void HCVLoadImage(void);
	void HCVGrayImage(void);
	void HCVThreshold(void);
	void HCVSplitImage(void);
	void HCVHistogram(void);
	void HCVResize(void);
	void HCVLabeling(void);

	double round(double num);
	int Labeling(IplImage* image, int nThreshold);
	void ImgCalibration(void);
	void DeletevPoint();
	void InitvPoint(int nWidth, int nHeight);
	int _Labeling(unsigned char* DataBuf, int nWidth, int nHeight, int nThreshold);
	void DetectLabelingRegion(int nLabelNumber, unsigned char* DataBuf, int nWidth, int nHeight);
	int __NRFIndNeighbor(unsigned char* DataBuf, int nWidth, int nHeight, int nPosX, int nPosY, int* StartX, int* StartY, int* EndX, int* EndY);
	int __Area(unsigned char* DataBuf, int StartX, int StartY, int ENdX, int EndY, int nWidth, int nLevel);

	
	IplImage* OriginalImg;
	HWND hWnd;
	CRect rectStaticClient;

	IplImage *Histogram(IplImage *pOriginalImg);
	int m_nRGBdata[6];

	IplImage *ImgZoom(IplImage *pOriginalImg, float fZoomInFactor);
};
