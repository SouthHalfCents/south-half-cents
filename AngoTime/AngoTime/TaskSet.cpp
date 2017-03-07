// TaskSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AngoTime.h"
#include "TaskSet.h"
#include "afxdialogex.h"


// CTaskSet �Ի���

IMPLEMENT_DYNAMIC(CTaskSet, CDialogEx)

CTaskSet::CTaskSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTaskSet::IDD, pParent)
{
	m_MyBrush.CreateSolidBrush(DIALOG_BACKGROUND_COLOR);
	m_MyHBrush = CreateSolidBrush(DIALOG_BACKGROUND_COLOR);
}

CTaskSet::~CTaskSet()
{
	if (m_MyBrush.GetSafeHandle())
		m_MyBrush.DeleteObject();
	DeleteObject(m_MyHBrush);
}

void CTaskSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDC_COMBO_TASK, m_cmbTask);
	DDX_Control(pDX, IDC_COMBO_HOUR, m_cmbHour);
	DDX_Control(pDX, IDC_COMBO_MIN, m_cmbMin);
	DDX_Control(pDX, IDC_COMBO_FREQUEN, m_cmbFrequen);
	DDX_Control(pDX, IDC_DATETIMEPICKER_ONCE, m_dateOnce);
	DDX_Control(pDX, IDC_CHECK_MON, m_chkMonday);
	DDX_Control(pDX, IDC_CHECK_TUES, m_chkTuesday);
	DDX_Control(pDX, IDC_CHECK_WEDN, m_chkWednesday);
	DDX_Control(pDX, IDC_CHECK_THUR, m_chkThursday);
	DDX_Control(pDX, IDC_CHECK_FRI, m_chkFriday);
	DDX_Control(pDX, IDC_CHECK_SAT, m_chkSaturday);
	DDX_Control(pDX, IDC_CHECK_SUN, m_chkSunday);
}


BEGIN_MESSAGE_MAP(CTaskSet, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDOK, &CTaskSet::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTaskSet::OnBnClickedCancel)
END_MESSAGE_MAP()


// CTaskSet ��Ϣ��������
HBRUSH CTaskSet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor != CTLCOLOR_EDIT && nCtlColor != CTLCOLOR_LISTBOX)
	{
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)m_MyHBrush;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}

BOOL CTaskSet::OnEraseBkgnd(CDC* pDC)
{
	CBrush *pOldBrush = pDC->SelectObject(&m_MyBrush);

	CRect Rect;
	GetClientRect(&Rect);

	pDC->FillRect(&Rect, &m_MyBrush);
	pDC->SelectObject(pOldBrush);
	return TRUE;

}



void CTaskSet::OnBnClickedOk()
{
	
	EndDialog(IDOK);
	
}


void CTaskSet::OnBnClickedCancel()
{
	
	EndDialog(IDCANCEL);
}