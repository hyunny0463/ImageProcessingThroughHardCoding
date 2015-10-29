
// ImageProcessingThroughHardCodingDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ImageProcessingThroughHardCoding.h"
#include "ImageProcessingThroughHardCodingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CImageProcessingThroughHardCodingDlg ��ȭ ����



CImageProcessingThroughHardCodingDlg::CImageProcessingThroughHardCodingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageProcessingThroughHardCodingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageProcessingThroughHardCodingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLD_RMIN, m_ctrlRGB[0]);
	DDX_Control(pDX, IDC_SLD_RMAX, m_ctrlRGB[1]);
	DDX_Control(pDX, IDC_SLD_GMIN, m_ctrlRGB[2]);
	DDX_Control(pDX, IDC_SLD_GMAX, m_ctrlRGB[3]);
	DDX_Control(pDX, IDC_SLD_BMIN, m_ctrlRGB[4]);
	DDX_Control(pDX, IDC_SLD_BMAX, m_ctrlRGB[5]);
	DDX_Text(pDX, IDC_STATIC_NOW_TIME, nowTimeDisplay);
}

BEGIN_MESSAGE_MAP(CImageProcessingThroughHardCodingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Cvload, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvload)
	ON_BN_CLICKED(Hcload, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcload)
	ON_BN_CLICKED(Cvgray, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvgray)
	ON_BN_CLICKED(Hcgray, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcgray)
	ON_BN_CLICKED(Cvsplit, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvsplit)
	ON_BN_CLICKED(Hcsplit, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcsplit)
	ON_BN_CLICKED(Cvthreshold, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvthreshold)
	ON_BN_CLICKED(Hcthreshold, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcthreshold)
	ON_BN_CLICKED(Cvhistogram, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvhistogram)
	ON_BN_CLICKED(Hchistogram, &CImageProcessingThroughHardCodingDlg::OnBnClickedHchistogram)
	ON_BN_CLICKED(Cvextraction, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvextraction)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_RMIN, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_RMAX, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_GMIN, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_GMAX, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_BMIN, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_BMAX, &CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB)
	ON_BN_CLICKED(Hccalibration, &CImageProcessingThroughHardCodingDlg::OnBnClickedHccalibration)
	ON_BN_CLICKED(Cvresize, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvresize)
	ON_BN_CLICKED(Hcresize, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcresize)
	ON_BN_CLICKED(Select1, &CImageProcessingThroughHardCodingDlg::OnBnClickedSelect1)
	ON_BN_CLICKED(Select2, &CImageProcessingThroughHardCodingDlg::OnBnClickedSelect2)
	ON_BN_CLICKED(Hclabeling, &CImageProcessingThroughHardCodingDlg::OnBnClickedHclabeling)
	ON_BN_CLICKED(Cvaddsub, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvaddsub)
	ON_BN_CLICKED(Hcaddsub, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcaddsub)
	ON_BN_CLICKED(Cvedgedetect, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvedgedetect)
	ON_BN_CLICKED(Hcedgedetect, &CImageProcessingThroughHardCodingDlg::OnBnClickedHcedgedetect)
	ON_BN_CLICKED(Cvcornerdet, &CImageProcessingThroughHardCodingDlg::OnBnClickedCvcornerdet)
	ON_BN_CLICKED(homework, &CImageProcessingThroughHardCodingDlg::OnBnClickedhomework)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_AVI_LOAD, &CImageProcessingThroughHardCodingDlg::OnBnClickedButtonAviLoad)
	ON_BN_CLICKED(IDC_BUTTON_OCV_CAMLOAD, &CImageProcessingThroughHardCodingDlg::OnBnClickedButtonOcvCamload)
END_MESSAGE_MAP()


// CImageProcessingThroughHardCodingDlg �޽��� ó����

BOOL CImageProcessingThroughHardCodingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog() ;

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT ( ( IDM_ABOUTBOX & 0xFFF0 ) == IDM_ABOUTBOX ) ;
	ASSERT ( IDM_ABOUTBOX < 0xF000 ) ;

	CMenu* pSysMenu = GetSystemMenu(FALSE) ;
	if (pSysMenu != NULL)
	{
		BOOL bNameValid ;
		CString strAboutMenu ;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX) ;
		ASSERT(bNameValid) ;
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR) ;
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu) ;
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon ( m_hIcon, TRUE ) ;			// ū �������� �����մϴ�.
	SetIcon ( m_hIcon, FALSE ) ;		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	Algorithm.SetResultDC ( GetDlgItem ( IDC_STATIC_ORIGINAL ) -> GetDC(),
							GetDlgItem ( IDC_STATIC_PROCESS1 ) -> GetDC(),
							GetDlgItem ( IDC_STATIC_PROCESS2 ) -> GetDC(),
							GetDlgItem ( IDC_STATIC_PROCESS3 ) -> GetDC() ) ;

	m_ctrlRGB[0].SetRange(-128, 127) ;
	m_ctrlRGB[1].SetRange(-128, 127) ;
	m_ctrlRGB[2].SetRange(-128, 127) ;
	m_ctrlRGB[3].SetRange(-128, 127) ;
	m_ctrlRGB[4].SetRange(-128, 127) ;
	m_ctrlRGB[5].SetRange(-128, 127) ;

	ColorSetting() ;

	SetTimer(0, 1000, NULL);

	return TRUE ;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CImageProcessingThroughHardCodingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CImageProcessingThroughHardCodingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CImageProcessingThroughHardCodingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvload()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVLoadImage();

}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcload()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.hWnd = GetDlgItem(IDC_STATIC_ORIGINAL)->GetSafeHwnd();
	GetDlgItem(IDC_STATIC_ORIGINAL)->GetClientRect(&(Algorithm.rectStaticClient));
	Algorithm.HCVLoadImage();

}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvgray()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVGrayImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcgray()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVGrayImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvsplit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVSplitImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcsplit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVSplitImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvthreshold()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVThreshold();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcthreshold()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVThreshold();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvhistogram()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVHistogram();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHchistogram()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVHistogram();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvextraction()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVColorExtraction();
}


void CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.m_nRGBdata[0] = m_ctrlRGB[0].GetPos();
	Algorithm.m_nRGBdata[1] = m_ctrlRGB[1].GetPos();
	Algorithm.m_nRGBdata[2] = m_ctrlRGB[2].GetPos();
	Algorithm.m_nRGBdata[3] = m_ctrlRGB[3].GetPos();
	Algorithm.m_nRGBdata[4] = m_ctrlRGB[4].GetPos();
	Algorithm.m_nRGBdata[5] = m_ctrlRGB[5].GetPos();

	*pResult = 0;
}


void CImageProcessingThroughHardCodingDlg::ColorSetting(void)
{
	m_ctrlRGB[0].SetPos(-128);
	Algorithm.m_nRGBdata[0] = -128;
	m_ctrlRGB[1].SetPos(127);
	Algorithm.m_nRGBdata[1] = 127;
	m_ctrlRGB[2].SetPos(-99);
	Algorithm.m_nRGBdata[2] = -99;
	m_ctrlRGB[3].SetPos(127);
	Algorithm.m_nRGBdata[3] = 127;
	m_ctrlRGB[4].SetPos(-85);
	Algorithm.m_nRGBdata[4] = -85;
	m_ctrlRGB[5].SetPos(49);
	Algorithm.m_nRGBdata[5] = 49;
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHccalibration()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.ImgCalibration();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvresize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVResize();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcresize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVResize();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedSelect1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int i = 0; i < 6; i++)
	{
		Algorithm.m_nSelect1RgbData[i] = Algorithm.m_nRGBdata[i];
	}
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedSelect2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int i = 0; i < 6; i++)
	{
		Algorithm.m_nSelect2RgbData[i] = Algorithm.m_nRGBdata[i];
	}
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHclabeling()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVLabeling();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvaddsub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVAddsub();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcaddsub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVAddsub();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvedgedetect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVEdgeDetection();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcedgedetect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.HCVEdgeDetection();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvcornerdet()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.OCVCornerDetection();
}

void CImageProcessingThroughHardCodingDlg::OnBnClickedhomework()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Algorithm.Homework();
}

void CImageProcessingThroughHardCodingDlg::OnBnClickedButtonAviLoad()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bAviLoadEnabled == FALSE)
	{
		SetTimer(1, 100, NULL);
		m_capAviView = cvCreateFileCapture(".\\Movies\\1.avi");
		m_bAviLoadEnabled = TRUE;
	}
	else
	{
		m_bAviLoadEnabled = FALSE;
		KillTimer(1);
	}
}

void CImageProcessingThroughHardCodingDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if (nIDEvent == 1)
	{
		cvGrabFrame(m_capAviView);
		IplImage* pFrameAviView = cvQueryFrame(m_capAviView);

		if (!pFrameAviView)
		{
			cvReleaseCapture(&m_capAviView);
			KillTimer(1);
		}
		else
		{
			UpdateData(TRUE);

			IplImage* pFrameFlipAviView = cvCreateImage(cvGetSize(pFrameAviView), IPL_DEPTH_8U, 3);
			cvFlip(pFrameAviView, pFrameFlipAviView);

			// Dispaly at window
			IplImage* pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
			CvvImage cvProcess0Img;
			CvvImage cvProcess1Img;

			cvResize(pFrameAviView, pReOriginalImg);
			cvProcess0Img.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
			cvProcess0Img.Show(GetDlgItem(IDC_STATIC_ORIGINAL)->GetDC()->m_hDC, 0, 0, cvProcess0Img.Width(), cvProcess0Img.Height());
			cvProcess0Img.Destroy();
			
			cvResize(pFrameFlipAviView, pReOriginalImg);
			cvProcess1Img.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
			cvProcess1Img.Show(GetDlgItem(IDC_STATIC_PROCESS1)->GetDC()->m_hDC, 0, 0, cvProcess1Img.Width(), cvProcess1Img.Height());
			cvProcess1Img.Destroy();
			UpdateData(FALSE);

			cvReleaseImage(&pFrameFlipAviView);
			cvReleaseImage(&pReOriginalImg);
		}
	}

	if (nIDEvent == 0)
	{
		UpdateData(TRUE);
		saveNowTime = COleDateTime::GetTickCount();

		nowTimeDisplay.Format(L"%d.%02d.%02d %02d:%02d:%02d", saveNowTime.GetYear(), saveNowTime.GetMonth(), saveNowTime.GetDay(), saveNowTime.GetHour(), saveNowTime.GetMinute(), saveNowTime.GetSecond());
		UpdateData(FALSE);
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CImageProcessingThroughHardCodingDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	cameraStop();

	if (m_capCamView)
	{
		cvReleaseCapture(&m_capCamView);
	}
}

void CImageProcessingThroughHardCodingDlg::OnBnClickedButtonOcvCamload()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bCameraProcessFlag == FALSE)
	{
		cameraStart();
		SetDlgItemText(IDC_BUTTON_OCV_CAMLOAD, L"CAM Stop");
	}
	else
	{
		cameraStop();
		SetDlgItemText(IDC_BUTTON_OCV_CAMLOAD, L"CAM Load");
	}
}

UINT ThreadGrabContinuousCam(LPVOID pParam)
{
	CImageProcessingThroughHardCodingDlg* image = ((CImageProcessingThroughHardCodingDlg*)pParam);
	UINT Retval = image->showContinuousImage();
	return Retval;
}

void CImageProcessingThroughHardCodingDlg::cameraStart(void)
{
	if (m_bCameraProcessFlag == FALSE)
	{
		m_bCameraProcessFlag = TRUE;

		if (m_pThread != NULL) // Thread status Ȯ��
		{
			AfxMessageBox(L"Thread is in use");
		}

		m_pThread = ::AfxBeginThread(ThreadGrabContinuousCam, this);

		if (m_pThread == NULL)
		{
			AfxMessageBox(L"Thread Error");
		}
	}
}

void CImageProcessingThroughHardCodingDlg::cameraStop(void)
{
	if (m_bCameraProcessFlag == TRUE)
	{
		m_bCameraProcessFlag = FALSE;

		if (m_pThread != NULL)
		{
			DWORD obj = WaitForSingleObject(m_pThread, INFINITE);
			if (obj == WAIT_TIMEOUT)
			{
				TerminateThread(m_pThread, 0);
			}
			else if (obj == WAIT_OBJECT_0)
			{
				printf("Thread End");
			}

			m_pThread = NULL;
		}
	}
}

bool CImageProcessingThroughHardCodingDlg::showContinuousImage(void)
{
	m_capCamView = cvCreateCameraCapture(0);	// 0�� ī�޶� �ڵ��� ����

	if (m_capCamView == (CvCapture*)0)
	{
		AfxMessageBox(L"Camera connection fail");
		OnBnClickedButtonOcvCamload();
		return FALSE;
	}

	else
	{
		m_bCameraConnectionFlag = TRUE;
	}

	IplImage* cameraImg;

	while (m_bCameraProcessFlag)
	{
		cameraImg = cvRetrieveFrame(m_capCamView);

		IplImage* pReOriginalImg = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
		cvResize(cameraImg, pReOriginalImg);

		CvvImage cvProcess0Img;
		cvProcess0Img.CopyOf(pReOriginalImg, pReOriginalImg->nChannels / 3);
		cvProcess0Img.Show(GetDlgItem(IDC_STATIC_ORIGINAL)->GetDC()->m_hDC, 0, 0, cvProcess0Img.Width(), cvProcess0Img.Height());
		cvProcess0Img.Destroy();

		cvReleaseImage(&pReOriginalImg);
	}

	return TRUE;
}