#include "stdafx.h"
#include "Algorithm.h"


CAlgorithm::CAlgorithm()
{
}


CAlgorithm::~CAlgorithm()
{
}

void CAlgorithm::SetResultDC(CDC* pOriginalDC, CDC* pProcess1DC, CDC* pProcess2DC, CDC* pProcess3DC)
{
	m_pOriginalDC = pOriginalDC;
	m_pProcess1DC = pProcess1DC;
	m_pProcess2DC = pProcess2DC;
	m_pProcess3DC = pProcess3DC;
}

void CAlgorithm::OCVLoadImage(void)
{
	CvvImage cvOriginalImg;
	OriginalImg = cvLoadImage("OriginalImg.bmp");
	IplImage* pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
	cvResize(OriginalImg, pReOriginalImg);
	cvOriginalImg.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
	cvOriginalImg.Show(m_pOriginalDC->m_hDC, 0, 0, cvOriginalImg.Width(), cvOriginalImg.Height());
	cvOriginalImg.Destroy();
}

void CAlgorithm::HCVLoadImage(void)
{
	FILE *infile;
	infile = fopen("OriginalImg.bmp", "rb");

	BITMAPFILEHEADER hf;
	fread(&hf, sizeof(BITMAPFILEHEADER), 1, infile); // ������带����
	BITMAPINFOHEADER hInfo;
	fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, infile); // ������带����

	// ������Ÿ�������Ҹ޸��Ҵ�
	BYTE *lpImg = new BYTE[hInfo.biSizeImage];
	fread(lpImg, sizeof(char), hInfo.biSizeImage, infile);
	fclose(infile);

	HDC hdc = ::GetDC(hWnd);
	LPBITMAPINFO  bitmapColorinfo = NULL;
	bitmapColorinfo = (BITMAPINFO*)(new char[sizeof(BITMAPINFOHEADER) + 256 * sizeof(RGBQUAD)]);
	bitmapColorinfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapColorinfo->bmiHeader.biWidth = hInfo.biWidth;
	bitmapColorinfo->bmiHeader.biHeight = hInfo.biHeight;
	bitmapColorinfo->bmiHeader.biPlanes = hInfo.biPlanes;
	bitmapColorinfo->bmiHeader.biCompression = hInfo.biCompression;
	bitmapColorinfo->bmiHeader.biBitCount = hInfo.biBitCount;
	bitmapColorinfo->bmiHeader.biSizeImage = hInfo.biSize;
	bitmapColorinfo->bmiHeader.biXPelsPerMeter = hInfo.biXPelsPerMeter;
	bitmapColorinfo->bmiHeader.biYPelsPerMeter = hInfo.biYPelsPerMeter;
	bitmapColorinfo->bmiHeader.biClrUsed = hInfo.biClrUsed;
	bitmapColorinfo->bmiHeader.biClrImportant = hInfo.biClrImportant;

	for (int j = 0; j < 256; j++)
	{
		bitmapColorinfo->bmiColors[j].rgbRed = (UINT8)j;
		bitmapColorinfo->bmiColors[j].rgbGreen = (UINT8)j;
		bitmapColorinfo->bmiColors[j].rgbBlue = (UINT8)j;
		bitmapColorinfo->bmiColors[j].rgbReserved = 0;
	}

	::SetStretchBltMode(hdc, COLORONCOLOR);
	::StretchDIBits(hdc, 0, 0, rectStaticClient.Width(), rectStaticClient.Height(), 0, 0, 640, 480, lpImg, bitmapColorinfo, DIB_RGB_COLORS, SRCCOPY);
	::ReleaseDC(hWnd, hdc);
}

void CAlgorithm::OCVThreshold(void)
{
	CvvImage cvProcess1Img, cvProcess2Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pThresholdImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGrayImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvCvtColor(OriginalImg, pGrayImg, CV_RGB2GRAY);

	cvThreshold(pGrayImg, pThresholdImg, 200, 255, CV_THRESH_BINARY);

	cvResize(pGrayImg, pReProcess1Img);
	cvResize(pThresholdImg, pReProcess2Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvReleaseImage(&pGrayImg);
	cvReleaseImage(&pThresholdImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
}

void CAlgorithm::HCVThreshold(void)
{
	CvvImage cvProcess1Img, cvProcess2Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pGrayImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pThresholdImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			double dblNtscR = 0.299*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 0]));
			double dblNtscG = 0.587*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 1]));
			double dblNtscB = 0.114*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 2]));
			pGrayImg->imageData[y * 640 + x] = round(dblNtscR + dblNtscG + dblNtscB);
		}
	}

	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			if ((BYTE)(pGrayImg->imageData[y * 640 + x]) < 200)
			{
				pThresholdImg->imageData[y * 640 + x] = (BYTE)0;
			}
			else
			{
				pThresholdImg->imageData[y * 640 + x] = (BYTE)255;
			}
		}
	}

	cvResize(pGrayImg, pReProcess1Img);
	cvResize(pThresholdImg, pReProcess2Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvReleaseImage(&pGrayImg);
	cvReleaseImage(&pThresholdImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
}

void CAlgorithm::OCVGrayImage(void)
{
	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pGray1Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGray2Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGray3Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvCvtColor(OriginalImg, pGray1Img, CV_RGB2GRAY);
	cvCvtColor(OriginalImg, pGray2Img, CV_RGB2GRAY);
	cvCvtColor(OriginalImg, pGray3Img, CV_RGB2GRAY);

	cvResize(pGray1Img, pReProcess1Img);
	cvResize(pGray2Img, pReProcess2Img);
	cvResize(pGray3Img, pReProcess3Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pGray1Img);
	cvReleaseImage(&pGray2Img);
	cvReleaseImage(&pGray3Img);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
	cvReleaseImage(&pReProcess3Img);
}

void CAlgorithm::HCVGrayImage(void)
{
	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pGray1Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGray2Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGray3Img = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvCvtColor(OriginalImg, pGray1Img, CV_RGB2GRAY);

	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			pGray2Img->imageData[y * 640 + x] = (((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 0])
				+ (BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 1])
				+ (BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 2])) / 3);

			double dblNtscR = 0.299*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 0]));
			double dblNtscG = 0.587*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 1]));
			double dblNtscB = 0.114*((BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 2]));
			pGray3Img->imageData[y * 640 + x] = round(dblNtscR + dblNtscG + dblNtscB);
		}
	}

	cvResize(pGray1Img, pReProcess1Img);
	cvResize(pGray2Img, pReProcess2Img);
	cvResize(pGray3Img, pReProcess3Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pGray1Img);
	cvReleaseImage(&pGray2Img);
	cvReleaseImage(&pGray3Img);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
	cvReleaseImage(&pReProcess3Img);
}

void CAlgorithm::OCVSplitImage(void)
{
	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pChannelRedImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pChannelGreenImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pChannelBlueImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvSplit(OriginalImg, pChannelRedImg, pChannelGreenImg, pChannelBlueImg, NULL);

	cvResize(pChannelRedImg, pReProcess1Img);
	cvResize(pChannelGreenImg, pReProcess2Img);
	cvResize(pChannelBlueImg, pReProcess3Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
	cvReleaseImage(&pReProcess3Img);
	cvReleaseImage(&pChannelRedImg);
	cvReleaseImage(&pChannelGreenImg);
	cvReleaseImage(&pChannelBlueImg);
}

void CAlgorithm::HCVSplitImage(void)
{
	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pRedImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pGreenImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);
	IplImage *pBlueImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			pRedImg->imageData[y * 640 + x] = (BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 0]);
			pGreenImg->imageData[y * 640 + x] = (BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 1]);
			pBlueImg->imageData[y * 640 + x] = (BYTE)(OriginalImg->imageData[y * 640 * 3 + 3 * x + 2]);
		}
	}

	cvResize(pRedImg, pReProcess1Img);
	cvResize(pGreenImg, pReProcess2Img);
	cvResize(pBlueImg, pReProcess3Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();

	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pRedImg);
	cvReleaseImage(&pGreenImg);
	cvReleaseImage(&pBlueImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
	cvReleaseImage(&pReProcess3Img);
}

void CAlgorithm::OCVHistogram(void)
{
	CvvImage cvProcess1Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pGrayImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvCvtColor(OriginalImg, pGrayImg, CV_RGB2GRAY);

	cvResize(pGrayImg, pReProcess1Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	int i, j, bin_size = 256;
	int tmp = 0;

	float ranges[] = { 0, 255 };
	float *hist_range[] = { ranges };

	int hist_height = 128;
	int hist_width = 256;

	CvHistogram *hist = cvCreateHist(1, &bin_size, CV_HIST_ARRAY, hist_range, 1);

	cvCalcHist(&pGrayImg, hist, 0, NULL);

	float max_bin_value = 0;
	float min_bin_value = 0;
	int max_level = 0;
	int min_level = 0;
	cvGetMinMaxHistValue(hist, &min_bin_value, &max_bin_value, &min_level, &max_level);

	IplImage *hist_image = cvCreateImage(cvSize(hist_width, hist_height), IPL_DEPTH_8U, 1);

	int tmp_hist_height = cvRound(max_bin_value);

	IplImage *tmp_hist_image1 = cvCreateImage(cvSize(hist_width, tmp_hist_height), IPL_DEPTH_8U, 1);
	IplImage *tmp_hist_image2 = cvCreateImage(cvSize(hist_width, hist_height), IPL_DEPTH_8U, 1);

	cvSetZero(tmp_hist_image1);

	for (i = 0; i < hist_width; i++)
	{
		tmp = tmp_hist_height - cvRound(cvQueryHistValue_1D(hist, i));

		if (tmp == 0 || tmp > tmp_hist_height) continue;

		for (j = tmp - 1; j >= 0; j--)
		{
			cvSetReal2D(tmp_hist_image1, j, i, 192.0);
		}
	}

	cvResize(tmp_hist_image1, tmp_hist_image2, CV_INTER_CUBIC);

	for (i = 0; i < hist_height; i++)
	{
		for (j = 0; j < hist_width; j++)
		{
			cvSetReal2D(hist_image, i, j, cvGetReal2D(tmp_hist_image2, i, j));
		}
	}

	cvResize(hist_image, pReProcess3Img);

	cvProcess3Img.CopyOf(pReProcess3Img);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());

	cvReleaseHist(&hist);

	cvReleaseImage(&tmp_hist_image1);
	cvReleaseImage(&tmp_hist_image2);
	cvReleaseImage(&pGrayImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess3Img);
}

void CAlgorithm::HCVHistogram(void)
{
	CvvImage cvProcess1Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *hist_image = cvCreateImage(cvSize(256, 256), IPL_DEPTH_8U, 1);
	IplImage *pGrayImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	// ���� ��ȯ
	cvCvtColor(OriginalImg, pGrayImg, CV_RGB2GRAY);

	int i, vmax, vmin;
	int hist[256];

	for (i = 0; i < 256; i++)
	{
		hist[i] = 0;
	}

	// ������ ����
	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			int gv = (BYTE)pGrayImg->imageData[x + y * 640];
			hist[gv]++;
		}
	}

	// ������׷� ũ�� ����ȭ
	vmin = 1000000;
	vmax = 0;

	for (i = 0; i < 256; i++)
	{
		if (hist[i] <= vmin) vmin = hist[i];
		if (hist[i] >= vmax) vmax = hist[i];
	}

	if (vmax == vmin) return;

	float vd = (float)(vmax - vmin);

	for (i = 0; i < 256; i++)
	{
		hist[i] = (int)(((float)hist[i] - vmin)*255.0 / vd);
	}

	for (int y = 0; y < 256 * 256; y++)
	{
		hist_image->imageData[y] = 190; // ���
	}

	for (int x = 0; x < 256; x++)
	{
		for (int y = 0; y < hist[x]; y++)
		{
			hist_image->imageData[(255 - y) * 256 + x] = 0; // ����
		}
	}

	cvResize(pGrayImg, pReProcess1Img);
	cvResize(hist_image, pReProcess3Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pGrayImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess3Img);
}

void CAlgorithm::OCVColorExtraction(void)
{
	CvvImage cvOriginalImg;
	IplImage *pOriginalImg;
	pOriginalImg = cvLoadImage("OriginalImg2.jpg");
	IplImage *pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);

	cvResize(pOriginalImg, pReOriginalImg);

	cvOriginalImg.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
	cvOriginalImg.Show( m_pOriginalDC->m_hDC, 0, 0, cvOriginalImg.Width(), cvOriginalImg.Height());
	cvOriginalImg.Destroy();

	cvReleaseImage(&pReOriginalImg);

	// Color Extraction Part
	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
	IplImage *pReProcess2Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
	IplImage *pRedImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
	IplImage *pGreenImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
	IplImage *pBlueImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
	IplImage *pHistoImg = cvCreateImage(cvSize(256, 128), IPL_DEPTH_8U, 3);
	IplImage *pCombineHistoImg = cvCreateImage(cvSize(256*2, 128*2), IPL_DEPTH_8U, 3);
	IplImage *pExtractionImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);

	// ä�� �и�
	cvSplit(pOriginalImg, pRedImg, pGreenImg, pBlueImg, NULL);
	// ������׷� ���
	pHistoImg = Histogram(pRedImg);
	cvSetImageROI(pCombineHistoImg, cvRect(0, 0, pHistoImg->width, pHistoImg->height));
	cvCopy(pHistoImg, pCombineHistoImg);
	pHistoImg = Histogram(pGreenImg);
	cvSetImageROI(pCombineHistoImg, cvRect( pHistoImg->width, 0, pHistoImg->width, pHistoImg->height));
	cvCopy(pHistoImg, pCombineHistoImg);
	pHistoImg = Histogram(pBlueImg);
	cvSetImageROI(pCombineHistoImg, cvRect(0, pHistoImg->height, pHistoImg->width, pHistoImg->height));
	cvCopy(pHistoImg, pCombineHistoImg);
	cvResetImageROI(pCombineHistoImg);

	// �� ����
	for (int y = 0; y < 480; ++y)
	{
		for (int x = 0; x < 640; ++x)
		{
			if ((pRedImg->imageData[x + y * 640] >= m_nRGBdata[0] && pRedImg->imageData[x + y * 640] <= m_nRGBdata[1]) &&
				(pGreenImg->imageData[x + y * 640] >= m_nRGBdata[2] && pGreenImg->imageData[x + y * 640] <= m_nRGBdata[3]) &&
				(pGreenImg->imageData[x + y * 640] >= m_nRGBdata[4] && pGreenImg->imageData[x + y * 640] >= m_nRGBdata[5]))
			{
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 0] = pOriginalImg->imageData[x * 3 + y * 640 * 3 + 0];
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 1] = pOriginalImg->imageData[x * 3 + y * 640 * 3 + 1];
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 2] = pOriginalImg->imageData[x * 3 + y * 640 * 3 + 2];
			}

			else
			{
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 0];
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 1];
				pExtractionImg->imageData[x * 3 + y * 640 * 3 + 2];
			}
		}
	}

	// ������ ���̱�
	cvResize(pExtractionImg, pReProcess1Img);
	cvResize(pCombineHistoImg, pReProcess2Img);

	// ������ color image
	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvReleaseImage(&pRedImg);
	cvReleaseImage(&pGreenImg);
	cvReleaseImage(&pBlueImg);
	cvReleaseImage(&pHistoImg);
	cvReleaseImage(&pCombineHistoImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);
}

void CAlgorithm::ImgCalibration(void)
{
	//Original Image Load & Show
	CvvImage cvOriginalImg;
	IplImage *pOriginalImg;
	pOriginalImg = cvLoadImage("OriginalImg3.jpg");
	IplImage *pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);

	cvResize(pOriginalImg, pReOriginalImg);

	cvOriginalImg.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
	cvOriginalImg.Show(m_pOriginalDC->m_hDC, 0, 0, cvOriginalImg.Width(), cvOriginalImg.Height());

	cvReleaseImage(&pReOriginalImg);

	//Calibration
	CvvImage cvProcess1Img, cvProcess2Img;
	IplImage *pProcess1Img = cvCreateImage(cvSize(1280, 1280), IPL_DEPTH_8U, 3);
	IplImage *pReProcess1Img = cvCreateImage(cvSize(290, 290), IPL_DEPTH_8U, 3);
	int nWidth = 1280;  // +140
	int nHeight = 1280; // +140

	//Circle Calibration
	int nFocalLength = 445; // �����Ÿ�(F)

	for (int nCalibrationY = 0; nCalibrationY < nWidth; nCalibrationY++)
	{
		for (int nCalibrationX = 0; nCalibrationX < nHeight; nCalibrationX++)
		{
			int x = abs(nCalibrationX - nWidth / 2);
			int y = abs(nCalibrationY - nHeight / 2);
			double dblLength = sqrt((double)(x*x + y*y + nFocalLength*nFocalLength));

			int nTargetY, nTargetX;

			if (nCalibrationX < nWidth / 2 && nCalibrationY < nHeight / 2) // 1��и��� ����
			{
				nTargetX = pOriginalImg->width / 2 - x * nFocalLength / dblLength;
				nTargetY = pOriginalImg->height / 2 - y * nFocalLength / dblLength;
			}

			else if (nCalibrationX < nWidth / 2 && nCalibrationY >= nHeight / 2) // 2��и��� ����
			{
				nTargetX = pOriginalImg->width / 2 - x * nFocalLength / dblLength;
				nTargetY = pOriginalImg->height / 2 + y * nFocalLength / dblLength;
			}

			else if (nCalibrationX >= nWidth / 2 && nCalibrationY < nHeight / 2) // 3��и��� ����
			{
				nTargetX = pOriginalImg->width / 2 + x * nFocalLength / dblLength;
				nTargetY = pOriginalImg->height / 2 - y * nFocalLength / dblLength;
			}

			else if (nCalibrationX >= nWidth / 2 && nCalibrationY >= nHeight / 2) // 4��и��� ����
			{
				nTargetX = pOriginalImg->width / 2 + x * nFocalLength / dblLength;
				nTargetY = pOriginalImg->height / 2 + y * nFocalLength / dblLength;
			}

			// ������ ��ǥ�� �̿��Ͽ� ������ ���� ( �÷� �̹��� )
			pProcess1Img->imageData[nCalibrationY * 1280 * 3 + nCalibrationX * 3 + 0] = pOriginalImg->imageData[nTargetY * 1280 * 3 + nTargetX * 3 + 0];
			pProcess1Img->imageData[nCalibrationY * 1280 * 3 + nCalibrationX * 3 + 1] = pOriginalImg->imageData[nTargetY * 1280 * 3 + nTargetX * 3 + 1];
			pProcess1Img->imageData[nCalibrationY * 1280 * 3 + nCalibrationX * 3 + 2] = pOriginalImg->imageData[nTargetY * 1280 * 3 + nTargetX * 3 + 2];
		}
	}

	cvResize(pProcess1Img, pReProcess1Img, CV_INTER_LINEAR);

	// �ְ� ���� ����
	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	cvReleaseImage(&pReProcess1Img);
}

void CAlgorithm::OCVResize(void)
{

}

void CAlgorithm::HCVResize(void)
{
	// Orignal Image Load & Show
	CvvImage cvOriginalImg;
	IplImage * pOriginalImg;
	pOriginalImg = cvLoadImage("OriginalImg.jpg");
	IplImage *pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);

	cvResize(pOriginalImg, pReOriginalImg);

	cvOriginalImg.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
	cvOriginalImg.Show(m_pOriginalDC->m_hDC, 0, 0, cvOriginalImg.Width(), cvOriginalImg.Height());
	cvOriginalImg.Destroy();

	cvReleaseImage(&pReOriginalImg);

	CvvImage cvProcess1Img, cvProcess2Img, cvProcess3Img;
	IplImage *pReProcess1Img;
	IplImage *pReProcess2Img;
	IplImage *pReProcess3Img = cvCreateImage(cvSize(1280, 960), IPL_DEPTH_8U, 3);

	pReProcess1Img = ImgZoom(pOriginalImg, 2.0);
	pReProcess2Img = ImgZoom(pOriginalImg, 0.25);
	cvResize(pOriginalImg, pReProcess3Img, CV_INTER_LINEAR);
	cvSub(pReProcess1Img, pReProcess3Img, pReProcess3Img);

	// Ȯ�� ����
	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	// ��� ����
	cvProcess2Img.CopyOf(pReProcess2Img, pReProcess2Img->nChannels / 3);
	cvProcess2Img.Show(m_pProcess2DC->m_hDC, 0, 0, cvProcess2Img.Width(), cvProcess2Img.Height());
	cvProcess2Img.Destroy();
	
	// Ȯ�� ���� ��
	cvProcess3Img.CopyOf(pReProcess3Img, pReProcess3Img->nChannels / 3);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());
	cvProcess3Img.Destroy();

	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess2Img);

}

double CAlgorithm::round(double num)
{
	bool bNumMinus = FALSE;

	if (num < 0)
	{
		num = num * -1;
		bNumMinus = TRUE;
	}

	double dblResult;

	if ( (int)(num * 10) % 10 < 5 )
	{
		dblResult = floor(num);
	}
	else
	{
		dblResult = ceil(num);
	}

	if (bNumMinus == TRUE)
	{
		dblResult = dblResult * -1;
	}

	return dblResult;
}

IplImage *CAlgorithm::Histogram(IplImage *pOriginalImg)
{
	CvvImage cvProcess1Img, cvProcess3Img;
	IplImage *pReProcess1Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pReProcess3Img = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 1);
	IplImage *pGrayImg = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 1);

	cvCvtColor(pOriginalImg, pGrayImg, CV_RGB2GRAY);

	cvResize(pGrayImg, pReProcess1Img);

	cvProcess1Img.CopyOf(pReProcess1Img, pReProcess1Img->nChannels / 3);
	cvProcess1Img.Show(m_pProcess1DC->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
	cvProcess1Img.Destroy();

	int i, j, bin_size = 256;
	int tmp = 0;

	float ranges[] = { 0, 255 };
	float *hist_range[] = { ranges };

	int hist_height = 128;
	int hist_width = 256;

	CvHistogram *hist = cvCreateHist(1, &bin_size, CV_HIST_ARRAY, hist_range, 1);

	cvCalcHist(&pGrayImg, hist, 0, NULL);

	float max_bin_value = 0;
	float min_bin_value = 0;
	int max_level = 0;
	int min_level = 0;
	cvGetMinMaxHistValue(hist, &min_bin_value, &max_bin_value, &min_level, &max_level);

	IplImage *hist_image = cvCreateImage(cvSize(hist_width, hist_height), IPL_DEPTH_8U, 1);

	int tmp_hist_height = cvRound(max_bin_value);

	IplImage *tmp_hist_image1 = cvCreateImage(cvSize(hist_width, tmp_hist_height), IPL_DEPTH_8U, 1);
	IplImage *tmp_hist_image2 = cvCreateImage(cvSize(hist_width, hist_height), IPL_DEPTH_8U, 1);

	cvSetZero(tmp_hist_image1);

	for (i = 0; i < hist_width; i++)
	{
		tmp = tmp_hist_height - cvRound(cvQueryHistValue_1D(hist, i));

		if (tmp == 0 || tmp > tmp_hist_height) continue;

		for (j = tmp - 1; j >= 0; j--)
		{
			cvSetReal2D(tmp_hist_image1, j, i, 192.0);
		}
	}

	cvResize(tmp_hist_image1, tmp_hist_image2, CV_INTER_CUBIC);

	for (i = 0; i < hist_height; i++)
	{
		for (j = 0; j < hist_width; j++)
		{
			cvSetReal2D(hist_image, i, j, cvGetReal2D(tmp_hist_image2, i, j));
		}
	}

	cvResize(hist_image, pReProcess3Img);

	cvProcess3Img.CopyOf(pReProcess3Img);
	cvProcess3Img.Show(m_pProcess3DC->m_hDC, 0, 0, cvProcess3Img.Width(), cvProcess3Img.Height());

	cvReleaseHist(&hist);

	cvReleaseImage(&tmp_hist_image1);
	cvReleaseImage(&tmp_hist_image2);
	cvReleaseImage(&pGrayImg);
	cvReleaseImage(&pReProcess1Img);
	cvReleaseImage(&pReProcess3Img);

	return hist_image;
}

IplImage *CAlgorithm::ImgZoom(IplImage *pOriginalImg, float fZoomInFactor)
{
	int nWidth = pOriginalImg->width;
	int nNewHeight = pOriginalImg->height * fZoomInFactor;
	int nNewWidth = pOriginalImg->width * fZoomInFactor;
	int nHeightm1 = pOriginalImg->height - 1;
	int nWidthm1 = pOriginalImg->width - 1;
	float fOrgY, fOrgX;	// �� �̹��� ���� �ش� ��ǥ ( �Ǽ��� )
	int nOrgY, nOrgX;	// �� �̹��� ���� �ش� ��ǥ ( ������ )
	float fSy, fSx;		// �� 1.24 - 1 = 0.24
	float l1, l2, l3, l4;

	IplImage *pOutImg = cvCreateImage(cvSize(nNewWidth, nNewHeight), IPL_DEPTH_8U, 3);
	IplImage *pReOutImg = cvCreateImage(cvSize(nNewWidth, nNewHeight), IPL_DEPTH_8U, 3);

	for (int y = 0; y < nNewHeight; y++)
	{
		for (int x = 0; x < nNewWidth; x++)
		{
			fOrgY = y / fZoomInFactor;
			fOrgX = x / fZoomInFactor;
			nOrgY = floor(fOrgY);	//�� : floor(2.8) = 2.0
			nOrgX = floor(fOrgX);
			fSy = fOrgY - nOrgY;
			fSx = fOrgX - nOrgX;

			// ���� ����
			// �� �̹����� ������ ����� ��� 0�� �Ҵ�
			if (nOrgY < 0 || nOrgY > nHeightm1 || nOrgX < 0 || nOrgX > nWidthm1)
			{
				pOutImg->imageData[x * 3 + y + nNewWidth * 3 + 0] = 0;
				pOutImg->imageData[x * 3 + y + nNewWidth * 3 + 1] = 0;
				pOutImg->imageData[x * 3 + y + nNewWidth * 3 + 2] = 0;
			}
			// �� �̹����� ���� ���� ���� ���� ���� ���� ����
			else
			{
				for (int nChannel = 0; nChannel < 3; nChannel++)
				{
					l1 = (float)(BYTE)pOriginalImg->imageData[(nOrgX)* 3 + nOrgY * nWidth * 3 + nChannel];
					l1 = (float)(BYTE)pOriginalImg->imageData[(nOrgX + 1)* 3 + nOrgY * nWidth * 3 + nChannel];
					l1 = (float)(BYTE)pOriginalImg->imageData[(nOrgX + 1)* 3 + (nOrgY + 1) * nWidth * 3 + nChannel];
					l1 = (float)(BYTE)pOriginalImg->imageData[(nOrgX)* 3 + (nOrgY + 1) * nWidth * 3 + nChannel];

					// ���� ���� ������ ���� ���ο� ��Ⱚ ���
					BYTE nNewValue = (BYTE)(l1*(1 - fSx)*(1 - fSy) + l2*fSx*(1 - fSy) + l3*fSx*fSy + l4*(1 - fSx)*fSy);
					pOutImg->imageData[x * 3 + y * nNewWidth * 3 + nChannel] = nNewValue;
				}
			}
		}
	}

	return pOutImg;
}