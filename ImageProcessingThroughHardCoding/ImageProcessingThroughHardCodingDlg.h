
// ImageProcessingThroughHardCodingDlg.h : ��� ����
//

#pragma once
#include "Algorithm.h"


// CImageProcessingThroughHardCodingDlg ��ȭ ����
class CImageProcessingThroughHardCodingDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CImageProcessingThroughHardCodingDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IMAGEPROCESSINGTHROUGHHARDCODING_DIALOG };

	CAlgorithm Algorithm;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticOriginal();
	afx_msg void OnStnClickedStaticProcess1();
	afx_msg void OnStnClickedStaticProcess2();
	afx_msg void OnStnClickedStaticProcess3();
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

	CSliderCtrl m_ctrlRGB[6];
	int *GetRgbRange(void);
	void ColorSetting(void);
	afx_msg void OnBnClickedHccalibration();
	afx_msg void OnBnClickedCvresize();
	afx_msg void OnBnClickedHcresize();
};
