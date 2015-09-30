
// ImageProcessingThroughHardCodingDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ImageProcessingThroughHardCoding.h"
#include "ImageProcessingThroughHardCodingDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CImageProcessingThroughHardCodingDlg 대화 상자



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
END_MESSAGE_MAP()


// CImageProcessingThroughHardCodingDlg 메시지 처리기

BOOL CImageProcessingThroughHardCodingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	Algorithm.SetResultDC(GetDlgItem(IDC_STATIC_ORIGINAL)->GetDC(),
		GetDlgItem(IDC_STATIC_PROCESS1)->GetDC(),
		GetDlgItem(IDC_STATIC_PROCESS2)->GetDC(),
		GetDlgItem(IDC_STATIC_PROCESS3)->GetDC());

	m_ctrlRGB[0].SetRange(-128, 127);
	m_ctrlRGB[1].SetRange(-128, 127);
	m_ctrlRGB[2].SetRange(-128, 127);
	m_ctrlRGB[3].SetRange(-128, 127);
	m_ctrlRGB[4].SetRange(-128, 127);
	m_ctrlRGB[5].SetRange(-128, 127);

	ColorSetting();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CImageProcessingThroughHardCodingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CImageProcessingThroughHardCodingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVLoadImage();

}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.hWnd = GetDlgItem(IDC_STATIC_ORIGINAL)->GetSafeHwnd();
	GetDlgItem(IDC_STATIC_ORIGINAL)->GetClientRect(&(Algorithm.rectStaticClient));
	Algorithm.HCVLoadImage();

}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvgray()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVGrayImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcgray()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.HCVGrayImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvsplit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVSplitImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcsplit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.HCVSplitImage();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvthreshold()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVThreshold();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcthreshold()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.HCVThreshold();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvhistogram()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVHistogram();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHchistogram()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.HCVHistogram();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvextraction()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVColorExtraction();
}


void CImageProcessingThroughHardCodingDlg::OnNMCustomdrawRGB(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.ImgCalibration();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedCvresize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.OCVResize();
}


void CImageProcessingThroughHardCodingDlg::OnBnClickedHcresize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Algorithm.HCVResize();
}
