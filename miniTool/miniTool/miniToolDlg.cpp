
// miniToolDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "miniTool.h"
#include "miniToolDlg.h"
#include "afxdialogex.h"
#include "Common.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CminiToolDlg 对话框

#include<iostream>
using namespace std;


CminiToolDlg::CminiToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINITOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CminiToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_edit_input);
	DDX_Control(pDX, IDC_EDIT_OUTPUT, m_edit_output);
}

BEGIN_MESSAGE_MAP(CminiToolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CminiToolDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CminiToolDlg::OnBnClicked_Add_0x)
	ON_BN_CLICKED(IDC_BUTTON3, &CminiToolDlg::OnBnClicked_Reverse_Of_Byte)
	ON_BN_CLICKED(IDC_BUTTON7, &CminiToolDlg::OnBnClicked_Delete_Space)
	ON_BN_CLICKED(IDC_BUTTON2, &CminiToolDlg::OnBnClicked_Reverse_Of_Word)
	ON_BN_CLICKED(IDC_BUTTON4, &CminiToolDlg::OnBnClicked_Internal_Word_Reverse)
	ON_BN_CLICKED(IDC_BUTTON9, &CminiToolDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CminiToolDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON8, &CminiToolDlg::OnBnClicked_Enter)
	ON_BN_CLICKED(IDC_BUTTON5, &CminiToolDlg::OnBnClicked_XOR)
ON_BN_CLICKED(IDC_BUTTON6, &CminiToolDlg::OnBnClicked_Delete_0x)
ON_BN_CLICKED(IDC_BUTTON_BASE64_ENC, &CminiToolDlg::OnBnClickedButtonBase64Enc)
ON_BN_CLICKED(IDC_BUTTON_STRING2HEX, &CminiToolDlg::OnBnClicked_String2Hex)
ON_BN_CLICKED(IDC_BUTTON_HEX2STRING, &CminiToolDlg::OnBnClicked_Hex2String)
ON_BN_CLICKED(IDC_BUTTON_BASE64_DEC, &CminiToolDlg::OnBnClickedButtonBase64Dec)
ON_BN_CLICKED(IDC_BUTTON_BASE64_ENC2, &CminiToolDlg::OnBnClicked_Base64Enc_hex2str)
ON_BN_CLICKED(IDC_BUTTON_UPPER, &CminiToolDlg::OnBnClicked_Upper)
ON_BN_CLICKED(IDC_BUTTON_LOWER, &CminiToolDlg::OnBnClicked_Lower)
ON_BN_CLICKED(IDC_BUTTON_OCT_STR2BIN_STR, &CminiToolDlg::OnBnClickedButtonOctStr2binStr)
ON_EN_CHANGE(IDC_EDIT_INPUT, &CminiToolDlg::OnEnChangeEditInput)
END_MESSAGE_MAP()


// CminiToolDlg 消息处理程序

BOOL CminiToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CminiToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CminiToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CminiToolDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CminiToolDlg::OnBnClicked_Add_0x()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std::string substr = ",0x";
	std_str = CW2A(cstr.GetString());

	str_insert_by_XByte(std_str, substr, 1);
	std_str = std_str.substr(1, std_str.length() - 1);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Reverse_Of_Byte()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	if (std_str.length() & 1)
	{
		MessageBox(L"the byte length is incomplete");
		return;
	}

	str_reverse_by_1byte(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Delete_Space()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	str_delete_space(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Reverse_Of_Word()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	//if (0x01 == check_is_only_hex(std_str))
	//{
	//	MessageBox(L"Non-hex characters exist");
	//	return;
	//}

	if (0x00 != (std_str.length() & 7))
	{
		MessageBox(L"the word length is incomplete");
		return;
	}

	str_reverse_by_4byte(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Internal_Word_Reverse()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	if ((std_str.length() & 7) != 0)
	{
		MessageBox(L"the word length is incomplete");
		return;
	}

	str_word_internal_reverse(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClickedButton9()
{
	CString cstr, tmp_cstr;
	m_edit_input.GetWindowText(cstr);
	m_edit_output.GetWindowText(tmp_cstr);

	m_edit_input.SetWindowText(tmp_cstr);
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClickedButton10()
{
	m_edit_input.SetWindowText(L"");
	m_edit_output.SetWindowText(L"");
}


void CminiToolDlg::OnBnClicked_Enter()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	str_delete_enter(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_XOR()
{
	CString cstr;
	int i, j;
	m_edit_input.GetWindowText(cstr);

	std::string std_str, str1, str2;
	std_str = CW2A(cstr.GetString());
	for (i = 0; i < std_str.length(); i++)
		if (std_str[i] != '\r') //for win, enter is "\r\n"
			str1 += std_str[i];
		else
			break;

	for (j = i + 2; j < std_str.length(); j++)
		if (std_str[j] != '\r')
			str2 += std_str[j];
		else
			break;

	xor_u8(str1, str2, str1);

	cstr = str1.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Delete_0x()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	delete_0x(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}



void CminiToolDlg::OnBnClickedButtonBase64Enc()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	std_str = base.encode(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_String2Hex()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	std_str = StringToHex(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Hex2String()
{
	CString cstr;
	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	std_str = HexToString(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClickedButtonBase64Dec()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	std_str = base.decode(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Base64Enc_hex2str()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	std_str = HexToString(std_str);
	std_str = base.encode(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Upper()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	Upper(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClicked_Lower()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	Lower(std_str);

	cstr = std_str.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnBnClickedButtonOctStr2binStr()
{
	CString cstr;
	base64 base;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std::string str_res;
	std_str = CW2A(cstr.GetString());

	oct_str2bin_str(std_str, str_res);

	cstr = str_res.c_str();
	m_edit_output.SetWindowText(cstr);
}


void CminiToolDlg::OnEnChangeEditInput()
{
	CString cstr;
	stringstream ss;

	m_edit_input.GetWindowText(cstr);

	std::string std_str;
	std_str = CW2A(cstr.GetString());

	ss << std_str.length();

	std_str = ss.str();
	cstr = std_str.c_str();

	GetDlgItem(IDC_STATIC_CHAR_NUM)->SetWindowText(cstr);
}
