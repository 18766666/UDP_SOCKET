
// UDPDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "UDP.h"
#include "UDPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUDPDlg 对话框



CUDPDlg::CUDPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UDP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUDPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CUDPDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUDPDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT_SRC_IP, &CUDPDlg::OnEnChangeEditSrcIp)
	ON_EN_CHANGE(IDC_EDIT_SRC_POR, &CUDPDlg::OnEnChangeEditSrcPor)
	ON_EN_CHANGE(IDC_EDIT_DEST_IP, &CUDPDlg::OnEnChangeEditDestIp)
	ON_EN_CHANGE(IDC_EDIT_SEND, &CUDPDlg::OnEnChangeEditSend)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CUDPDlg::OnEnChangeEditText)
	ON_EN_CHANGE(IDC_EDIT_DEST_POR, &CUDPDlg::OnEnChangeEditDestPor)
END_MESSAGE_MAP()


// CUDPDlg 消息处理程序

BOOL CUDPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUDPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUDPDlg::OnPaint()
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
HCURSOR CUDPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUDPDlg::OnBnClickedButton1()
{
	HWND hIpWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_SRC_IP);
	HWND hPortWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_SRC_POR);
	char szIp[MAX_PATH] = { 0 };
	char szPort[MAX_PATH] = { 0 };
	::GetWindowText(hIpWnd, szIp, MAX_PATH);
	::GetWindowText(hPortWnd, szPort, MAX_PATH);
	if (Bind(szIp, atoi(szPort))) 
	{
		AddText("Bind OK.", "[bind]");
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CUDPDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hIpWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_DEST_IP);
	HWND hPortWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_DEST_POR);
	HWND hSendWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_SEND);
	char szIp[MAX_PATH] = { 0 };
	char szPort[MAX_PATH] = { 0 };
	char szSend[MAX_PATH] = { 0 };
	::GetWindowText(hIpWnd, szIp, MAX_PATH);
	::GetWindowText(hPortWnd, szPort, MAX_PATH);
	::GetWindowText(hSendWnd, szSend, MAX_PATH);
	Sendto(szSend, szIp, atoi(szPort));
}
void CUDPDlg::Sendto(char* lpszText, char* lpszIp, int iPort) {
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.S_un.S_addr = inet_addr(lpszIp);//ip字符串转换成整型
	sendto(m_sock,lpszText,(1+::lstrlen(lpszText)),0,(sockaddr*)(&addr), sizeof(addr));
}
void CUDPDlg::AddText(char* lpszText, char* lpszCaption)
{
	HWND hWnd = ::GetDlgItem(this->m_hWnd, IDC_EDIT_TEXT);
	char szText[MAX_PATH] = {0};
	::GetWindowText(hWnd, szText, MAX_PATH);
	::lstrcat(szText, "\r\n");
	::lstrcat(szText, lpszCaption);
	::lstrcat(szText, lpszText);
	::SetWindowText(hWnd, szText);
}
BOOL CUDPDlg::Bind(char* lpszIp, int iPort) {
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sock) {
		return FALSE;
	}
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.S_un.S_addr = inet_addr(lpszIp);//ip字符串转换成整型
	if (0 != bind(sock, (sockaddr*)(&addr), sizeof(addr))) 
	{
		return FALSE;
	}
	m_sock = sock;
	//多线程循环接收
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ThreadProc, this, NULL, NULL);
	return TRUE;
}
UINT CUDPDlg::ThreadProc(LPVOID lpVoid) {
	CUDPDlg* lpThis = (CUDPDlg*)lpVoid; //获取传入的指针
	lpThis->Recvfrom();
	return 0;
}
void CUDPDlg::Recvfrom() {
	char szBuf[MAX_PATH] = {0};
	sockaddr_in addr = { 0 };
	int iLen = sizeof(addr);
	while (true) {
		recvfrom(m_sock,szBuf,MAX_PATH,0, (sockaddr*)(&addr), &iLen);
		AddText(szBuf,"[recvfrom]");
	}
}
void CUDPDlg::OnEnChangeEditSrcIp()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUDPDlg::OnEnChangeEditSrcPor()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUDPDlg::OnEnChangeEditDestIp()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUDPDlg::OnEnChangeEditSend()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUDPDlg::OnEnChangeEditText()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUDPDlg::OnEnChangeEditDestPor()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
