
// ImageProcessingThroughHardCoding.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CImageProcessingThroughHardCodingApp:
// �� Ŭ������ ������ ���ؼ��� ImageProcessingThroughHardCoding.cpp�� �����Ͻʽÿ�.
//

class CImageProcessingThroughHardCodingApp : public CWinApp
{
public:
	CImageProcessingThroughHardCodingApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CImageProcessingThroughHardCodingApp theApp;