
// ImageProcessingThroughHardCodingDlg.h : 헤더 파일
//

#pragma once
#include "Algorithm.h"


// CImageProcessingThroughHardCodingDlg 대화 상자
class CImageProcessingThroughHardCodingDlg : public CDialogEx
{
// 생성입니다.
public:
	CImageProcessingThroughHardCodingDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMAGEPROCESSINGTHROUGHHARDCODING_DIALOG };

	CAlgorithm Algorithm;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCvload();
	afx_msg void OnBnClickedHcload();
	afx_msg void OnBnClickedCvgray();
	afx_msg void OnBnClickedHcgray();
	afx_msg void OnBnClickedCvsplit();
	afx_msg void OnBnClickedHcsplit();
	afx_msg void OnBnClickedCvthreshold();
	afx_msg void OnBnClickedHcthreshold();
	afx_msg void OnBnClickedCvhistogram();
	afx_msg void OnBnClickedHchistogram();
	afx_msg void OnBnClickedCvextraction();
	afx_msg void OnNMCustomdrawRGB(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedHccalibration();
	afx_msg void OnBnClickedCvresize();
	afx_msg void OnBnClickedHcresize();
	afx_msg void OnBnClickedSelect1();
	afx_msg void OnBnClickedSelect2();
	afx_msg void OnBnClickedHclabeling();
	afx_msg void OnBnClickedCvaddsub();
	afx_msg void OnBnClickedHcaddsub();
	afx_msg void OnBnClickedCvedgedetect();
	afx_msg void OnBnClickedHcedgedetect();
	afx_msg void OnBnClickedCvcornerdet();
	afx_msg void OnBnClickedhomework();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonAviLoad();
	afx_msg void OnBnClickedButtonOcvCamload();

	CSliderCtrl m_ctrlRGB[6];
	CvCapture* m_capAviView;
	CvCapture* m_capCamView;

	bool m_bAviLoadEnabled;
	bool m_bCameraProcessFlag;
	bool m_bCameraConnectionFlag;

	CString nowTimeDisplay;
	COleDateTime saveNowTime;
	CWinThread* m_pThread;

	int *GetRgbRange(void);
	void ColorSetting(void);
	void cameraStart(void);
	void cameraStop(void);
	bool showContinuousImage(void);	
};


static UINT ThreadGrabContinuousCam(LPVOID pParam);