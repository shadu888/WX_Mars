
// PSIMCoreDemo.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "PSIMCoreDemo.h"
#include "PSIMCoreDemoDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPSIMCoreDemoApp

BEGIN_MESSAGE_MAP(CPSIMCoreDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CPSIMCoreDemoApp 构造

CPSIMCoreDemoApp::CPSIMCoreDemoApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	m_pCallBack = NULL;
}


// 唯一的一个 CPSIMCoreDemoApp 对象

CPSIMCoreDemoApp theApp;


// CPSIMCoreDemoApp 初始化

BOOL CPSIMCoreDemoApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxInitRichEdit2();
	AfxEnableControlContainer();

	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	m_pCallBack = new CPSIMDemoCallBack(); // 继承CPSIMCallBack 进行回调处理;
	CPSIMCallFactory::CreateInstance(m_pCallBack); // 创建IMCall的实体对象;
	AfxGetPSIMCall()->Init();	// 获取IMCall的实体对象，进行初始化操作;

	CLoginDlg dlgLogin;
	INT_PTR iRes = dlgLogin.DoModal();
	if (iRes == IDOK)
	{
		CPSIMCoreDemoDlg dlg;
		m_pMainWnd = &dlg;
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: 在此放置处理何时用
			//  “确定”来关闭对话框的代码
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: 在此放置处理何时用
			//  “取消”来关闭对话框的代码
		}
		else if (nResponse == -1)
		{
			TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
			TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
		}
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	return FALSE;
}

int CPSIMCoreDemoApp::ExitInstance()
{
	AfxGetPSIMCall()->UnInit();
	CPSIMCallFactory::ReleaseInstance();

	if (m_pCallBack)
	{
		delete m_pCallBack;
		m_pCallBack = NULL;
	}

	return CWinApp::ExitInstance();
}