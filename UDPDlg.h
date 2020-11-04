
// UDPDlg.h: 头文件
//

#pragma once


// CUDPDlg 对话框
class CUDPDlg : public CDialogEx
{ 
public:
	SOCKET m_sock;

	void AddText(char* lpszText, char* lpszCaption);
	BOOL Bind(char *lpsszIp,int iPort);
	static UINT ThreadProc(LPVOID IpVoid);
	void Recvfrom();
	void Sendto(char *lpszText, char *lpszIp, int iPort);
	// 构造
public:
	CUDPDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UDP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEditSrcIp();
	afx_msg void OnEnChangeEditSrcPor();
	afx_msg void OnEnChangeEditDestIp();
	afx_msg void OnEnChangeEditSend();
	afx_msg void OnEnChangeEditText();
	afx_msg void OnEnChangeEditDestPor();
};
