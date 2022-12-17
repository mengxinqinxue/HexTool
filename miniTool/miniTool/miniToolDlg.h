
// miniToolDlg.h: 头文件
//

#pragma once


// CminiToolDlg 对话框
class CminiToolDlg : public CDialogEx
{
// 构造
public:
	CminiToolDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MINITOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_edit_input;
	CEdit m_edit_output;
	afx_msg void OnBnClicked_Add_0x();
	afx_msg void OnBnClicked_Reverse_Of_Byte();
	afx_msg void OnBnClicked_Delete_Space();
	afx_msg void OnBnClicked_Reverse_Of_Word();
	afx_msg void OnBnClicked_Internal_Word_Reverse();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClicked_Enter();
	afx_msg void OnBnClicked_XOR();
	afx_msg void OnBnClicked_Delete_0x();
	afx_msg void OnBnClickedButtonBase64Enc();
	afx_msg void OnBnClicked_String2Hex();
	afx_msg void OnBnClicked_Hex2String();
	afx_msg void OnBnClickedButtonBase64Dec();
	afx_msg void OnBnClicked_Base64Enc_hex2str();
	afx_msg void OnBnClicked_Upper();
	afx_msg void OnBnClicked_Lower();
	afx_msg void OnBnClickedButtonOctStr2binStr();
	afx_msg void OnEnChangeEditInput();
};
