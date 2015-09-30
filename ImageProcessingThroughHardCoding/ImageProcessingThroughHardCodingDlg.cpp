
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


// CImageProcessingThroughHardCodingDlg �޽��� ó����

BOOL CImageProcessingThroughHardCodingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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
