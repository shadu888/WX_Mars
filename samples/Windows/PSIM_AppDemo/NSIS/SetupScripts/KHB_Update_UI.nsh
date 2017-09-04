
# ===================== 外部插件以及宏 =============================
!include "StrFunc.nsh"
!include "WordFunc.nsh"
${StrRep}
${StrStr}
!include "LogicLib.nsh"
!include "nsDialogs.nsh"
!include "common.nsh"
!include "x64.nsh"
!include "MUI.nsh"
!include "WinVer.nsh" 

!insertmacro MUI_LANGUAGE "SimpChinese"
# ===================== 升级包版本 =============================
VIProductVersion             		"${PRODUCT_VERSION}"
VIAddVersionKey "ProductVersion"    "${PRODUCT_VERSION}"
VIAddVersionKey "ProductName"       "${PRODUCT_NAME}"
VIAddVersionKey "CompanyName"       "${PRODUCT_PUBLISHER}"
VIAddVersionKey "FileVersion"       "${PRODUCT_VERSION}"
VIAddVersionKey "InternalName"      "${EXE_NAME}"
VIAddVersionKey "FileDescription"   "${PRODUCT_NAME}"
VIAddVersionKey "LegalCopyright"    "${PRODUCT_LEGAL}"

!define PRODUCT_WEB_SITE "www.easylive.com"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\${EXE_NAME}"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

!define INSTALL_PAGE_CONFIG 			0
;!define INSTALL_PAGE_LICENSE 			1
!define INSTALL_PAGE_PROCESSING 		1
!define INSTALL_PAGE_FINISH 			2
!define INSTALL_PAGE_UNISTCONFIG 		3
!define INSTALL_PAGE_UNISTPROCESSING 	4
!define INSTALL_PAGE_UNISTFINISH 		5

InstallDirRegKey HKLM  "Software\Microsoft\Windows\CurrentVersion\App Paths\${EXE_NAME}" ""

# 自定义页面
Page custom DUIPage

# 卸载程序显示进度
UninstPage custom un.DUIPage

# ======================= DUILIB 自定义页面 =========================
Var hInstallDlg
Var sCmdFlag
Var sCmdSetupPath
Var sSetupPath 
Var sReserveData   #卸载时是否保留数据 
Var InstallState   #是在升级中还是升级完成  
Var UnInstallValue  #卸载的进度  

Var temp11
Var temp12
Function DUIPage
    StrCpy $InstallState "0"	#设置未升级完成状态
	InitPluginsDir   	
	SetOutPath "$PLUGINSDIR"
	File "${INSTALL_LICENCE_FILENAME}"
    File "${INSTALL_RES_PATH}"
	nsNiuniuSkin::InitSkinPage "$PLUGINSDIR\" "${INSTALL_LICENCE_FILENAME}" #指定插件路径及协议文件名称
    Pop $hInstallDlg
   	
	#设置控件显示升级路径 
	ReadRegStr $0 HKLM "Software\${PRODUCT_NAME}" "InstPath"
	${if} $0 == ""
	${else}
		 StrCpy $INSTDIR "$0" 
	${Endif}
    nsNiuniuSkin::SetDirValue "$INSTDIR"
	#设置升级包的标题及任务栏显示  
	nsNiuniuSkin::SetWindowTile "${PRODUCT_NAME}升级程序"
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_CONFIG}
	#nsNiuniuSkin::PrePage "wizardTab" 
    Call BindUIControls	
    nsNiuniuSkin::ShowPage	
FunctionEnd

Function un.DUIPage
FunctionEnd

#绑定卸载的事件 
Function un.BindUnInstUIControls
	GetFunctionAddress $0 un.ExitDUISetup
    nsNiuniuSkin::BindCallBack "btnUninstalled" $0
	
	GetFunctionAddress $0 un.onUninstall
    nsNiuniuSkin::BindCallBack "btnUnInstall" $0
	
	GetFunctionAddress $0 un.ExitDUISetup
    nsNiuniuSkin::BindCallBack "btnClose" $0
FunctionEnd

#绑定升级的界面事件 
Function BindUIControls
	# License页面
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnLicenseClose" $0

    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnLicenseMin" $0
 
	GetFunctionAddress $0 OnBtnLicenseClick
    nsNiuniuSkin::BindCallBack "btnAgreement" $0

    # 目录选择 页面
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnDirClose" $0

	GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnLicenseCancel" $0
    
    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnDirMin" $0
    
    GetFunctionAddress $0 OnBtnSelectDir
    nsNiuniuSkin::BindCallBack "btnSelectDir" $0
    
    GetFunctionAddress $0 OnBtnDirPre
    nsNiuniuSkin::BindCallBack "btnDirPre" $0
    
	GetFunctionAddress $0 OnBtnShowConfig
    nsNiuniuSkin::BindCallBack "btnAgree" $0
	
    GetFunctionAddress $0 OnBtnCancel
    nsNiuniuSkin::BindCallBack "btnDirCancel" $0
        
    GetFunctionAddress $0 OnBtnInstall
    nsNiuniuSkin::BindCallBack "btnInstall" $0

    # 升级进度 页面
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnDetailClose" $0

    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnDetailMin" $0
	
    # 升级完成 页面
    GetFunctionAddress $0 OnFinished
    nsNiuniuSkin::BindCallBack "btnRun" $0
    
    GetFunctionAddress $0 OnBtnMin
    nsNiuniuSkin::BindCallBack "btnFinishedMin" $0
    
    GetFunctionAddress $0 OnExitDUISetup
    nsNiuniuSkin::BindCallBack "btnClose" $0
	
	GetFunctionAddress $0 OnCheckLicenseClick
    nsNiuniuSkin::BindCallBack "chkAgree" $0
	
	GetFunctionAddress $0 OnBtnShowMore
    nsNiuniuSkin::BindCallBack "btnShowMore" $0
	
	GetFunctionAddress $0 OnBtnHideMore
    nsNiuniuSkin::BindCallBack "btnHideMore" $0
FunctionEnd

#根据选中的情况来控制按钮是否灰度显示 
Function OnCheckLicenseClick
	nsNiuniuSkin::GetCheckboxStatus "chkAgree"
    Pop $0
	${If} $0 == "0"        
		nsNiuniuSkin::SetControlAttribute "btnInstall" "enabled" "true"
	${Else}
		nsNiuniuSkin::SetControlAttribute "btnInstall" "enabled" "false"
    ${EndIf}
FunctionEnd

Function OnBtnLicenseClick
    ;nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_LICENSE}
	nsNiuniuSkin::SetControlAttribute "licenseshow" "visible" "true"
	nsNiuniuSkin::IsControlVisible "moreconfiginfo"
	Pop $0
	${If} $0 = 0        
		;pos="10,35,580,410"
		nsNiuniuSkin::SetControlAttribute "licenseshow" "pos" "10,35,590,410"
		nsNiuniuSkin::SetControlAttribute "editLicense" "height" "300"		
	${Else}
		nsNiuniuSkin::SetControlAttribute "licenseshow" "pos" "10,35,590,470"
		nsNiuniuSkin::SetControlAttribute "editLicense" "height" "360"
    ${EndIf}
	
FunctionEnd

# 添加一个空的Section，防止编译器报错
Section "None"
SectionEnd

# 开始升级
Function OnBtnInstall
    nsNiuniuSkin::GetCheckboxStatus "chkAgree"
    Pop $0
	StrCpy $0 "1"
	
	#如果未同意，直接退出 
	StrCmp $0 "0" InstallAbort 0
	
	CheckExe: 
	#此处检测当前是否有程序正在运行，如果正在运行，提示先卸载再升级 
	nsProcess::_FindProcess "${EXE_NAME}"
	Pop $R0
	${If} $R0 == 0
        nsNiuniuSkin::ShowMsgBox "提示" "${PRODUCT_NAME} 正在运行，确定继续升级么？" 1
		pop $0
		${If} $0 == 0
			; 取消不升级;
			goto InstallAbort
		${EndIf}

		Push "xsd.exe"
		Processwork::KillProcess

		Sleep 1000
		Goto CheckExe
    ${EndIf}		

	nsNiuniuSkin::GetDirValue
    Pop $0
    StrCmp $0 "" InstallAbort 0
	#$sCmdSetupPath表示 非命令行传递路径 的方式  
	StrCpy $sSetupPath "$0\"
    StrCpy $INSTDIR "$0"
	#写入注册信息 
	SetRegView 32
	WriteRegStr HKLM "Software\${PRODUCT_NAME}" "InstPath" "$sSetupPath"
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 420
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "false"
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_PROCESSING}
    nsNiuniuSkin::SetSliderRange "slrProgress" 0 100
	
    # 将这些文件暂存到临时目录
    #Call BakFiles
  
    #启动一个低优先级的后台线程
    GetFunctionAddress $0 ExtractFunc
    BgWorker::CallAndWait
	
    #还原文件
    #Call RestoreFiles
    
	#升级模式下不需要创建快捷方式等 
	#Call CreateShortcut
	#Call CreateUninstall
    	
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_FINISH}
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "true"
		
	StrCpy $InstallState "1"
InstallAbort:
FunctionEnd

Function ExtractFunc
    SetOutPath $INSTDIR
    File "${INSTALL_7Z_PATH}"
    GetFunctionAddress $R9 ExtractCallback
    nsis7z::ExtractWithCallback "$INSTDIR\${INSTALL_7Z_NAME}" $R9
	Delete "$INSTDIR\${INSTALL_7Z_NAME}"
	Sleep 100
FunctionEnd

Function ExtractCallback
    Pop $1
    Pop $2
    System::Int64Op $1 * 100
    Pop $3
    System::Int64Op $3 / $2
    Pop $0
    Sleep 10
    nsNiuniuSkin::SetSliderValue "slrProgress" $0
	Sleep 10
    ${If} $1 == $2
        nsNiuniuSkin::SetSliderValue "slrProgress" 100        				
    ${EndIf}
FunctionEnd

#升级界面点击退出，给出提示 
Function OnExitDUISetup
	${If} $InstallState == "0"		
		nsNiuniuSkin::ShowMsgBox "提示" "升级尚未完成，您确定退出么？" 1
		pop $0
		${If} $0 == 0
			goto endfun
		${EndIf}
	${EndIf}
	nsNiuniuSkin::ExitDUISetup
endfun:    
FunctionEnd

Function OnBtnMin
    SendMessage $hInstallDlg ${WM_SYSCOMMAND} 0xF020 0
FunctionEnd

Function OnBtnCancel
	nsNiuniuSkin::ExitDUISetup
FunctionEnd

#立即启动
Function OnFinished	
	Exec '"$INSTDIR\${EXE_NAME}" /un'
    Call OnExitDUISetup
FunctionEnd

Function OnBtnSelectDir
    nsNiuniuSkin::SelectInstallDir
    Pop $0
FunctionEnd

Function OnBtnShowMore
	;调整窗口高度 
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 480
	nsNiuniuSkin::SetControlAttribute "moreconfiginfo" "visible" "true"
	nsNiuniuSkin::SetControlAttribute "btnShowMore" "visible" "false"
	nsNiuniuSkin::SetControlAttribute "btnHideMore" "visible" "true"
	
FunctionEnd

Function OnBtnHideMore
	;调整窗口高度 
	nsNiuniuSkin::SetWindowSize $hInstallDlg 600 420
	nsNiuniuSkin::SetControlAttribute "moreconfiginfo" "visible" "false"
	nsNiuniuSkin::SetControlAttribute "btnShowMore" "visible" "true"
	nsNiuniuSkin::SetControlAttribute "btnHideMore" "visible" "false"
FunctionEnd

Function OnBtnShowConfig
    ;nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_CONFIG}
	nsNiuniuSkin::SetControlAttribute "licenseshow" "visible" "false"
FunctionEnd

Function OnBtnDirPre
    nsNiuniuSkin::PrePage "wizardTab"
FunctionEnd


# ============================== 回调函数 ====================================

# 函数名以“.”开头的一般作为回调函数保留.
# 函数名以“un.”开头的函数将会被创建在卸载程序里，因此，普通升级区段和函数不能调用卸载函数，而卸载区段和卸载函数也不能调用普通函数。

Function .onInit	
	#此处需要检测之前的升级情况，如果已经升级，将其目录信息默认写入地址栏 
	
FunctionEnd


# 升级成功以后.
Function .onInstSuccess

FunctionEnd

# 在升级失败后用户点击“取消”按钮时被调用.
Function .onInstFailed
    
FunctionEnd


# 每次用户更改升级路径的时候这段代码都会被调用一次.
Function .onVerifyInstDir
;nsNiuniuSkin::SetControlAttribute "txtNeed" "text" "AAAA"
;nsNiuniuSkin::ShowMsgBox "提示" "${PRODUCT_NAME} 正在运行，请退出后重试!" 0
FunctionEnd

# 卸载操作开始前.
Function un.onInit
    
FunctionEnd

# 卸载成功以后.
Function un.onUninstSuccess

FunctionEnd

Function un.ExitDUISetup
	nsNiuniuSkin::ExitDUISetup
FunctionEnd

#执行具体的卸载 
Function un.onUninstall
	nsNiuniuSkin::GetCheckboxStatus "chkReserveData"
    Pop $0
	StrCpy $sReserveData $0
		
	#此处检测当前是否有程序正在运行，如果正在运行，提示先卸载再升级 
	nsProcess::_FindProcess "${EXE_NAME}"
	Pop $R0
	
	${If} $R0 == 0
		nsNiuniuSkin::ShowMsgBox "提示" "${PRODUCT_NAME} 正在运行，请退出后重试!" 0
		goto InstallAbort
    ${EndIf}
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "false"
	nsNiuniuSkin::SetControlAttribute "lblInstalling" "text" "正在卸载..."
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_UNISTPROCESSING}
	nsNiuniuSkin::SetSliderRange "slrProgress" 0 100
	IntOp $UnInstallValue 0 + 1
	SetRegView 32
	;DeleteRegKey HKLM "Software\${PRODUCT_NAME}"	
	DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
	DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"

	; 删除快捷方式
	SetShellVarContext all
	
	Delete "$INSTDIR\${PRODUCT_NAME}.url"
	Delete "$INSTDIR\Uninst.exe"
 
	Delete "$DESKTOP\小易主播伴侣.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\小易主播伴侣.lnk"
	Delete "$SMPROGRAMS\$ICONS_GROUP\小易主播伴侣.lnk"

	;RMDir "$SMPROGRAMS\$ICONS_GROUP"
	
	RMDir /r /REBOOTOK "$INSTDIR"
	
	/* Delete "$SMPROGRAMS\${PRODUCT_NAME}\${PRODUCT_NAME}.lnk"
	Delete "$SMPROGRAMS\${PRODUCT_NAME}\卸载${PRODUCT_NAME}.lnk"
	RMDir "$SMPROGRAMS\${PRODUCT_NAME}\"
	Delete "$DESKTOP\${PRODUCT_NAME}.lnk" */
	
	#删除开机启动  
    Delete "$SMSTARTUP\${PRODUCT_NAME}.lnk"
	SetShellVarContext current
	
	IntOp $UnInstallValue $UnInstallValue + 8
    
	#删除文件 
	GetFunctionAddress $0 un.RemoveFiles
    BgWorker::CallAndWait	
	
	;SetAutoClose true
	
	InstallAbort:
FunctionEnd

#在线程中删除文件，以便显示进度 
Function un.RemoveFiles
	${Locate} "$INSTDIR" "/G=0 /M=*.*" "un.onDeleteFileFound"
	StrCpy $InstallState "1"
	nsNiuniuSkin::SetControlAttribute "btnClose" "enabled" "true"
	nsNiuniuSkin::SetSliderValue "slrProgress" 100
	nsNiuniuSkin::ShowPageItem "wizardTab" ${INSTALL_PAGE_UNISTFINISH}
FunctionEnd


#卸载程序时删除文件的流程，如果有需要过滤的文件，在此函数中添加  
Function un.onDeleteFileFound
    ; $R9    "path\name"
    ; $R8    "path"
    ; $R7    "name"
    ; $R6    "size"  ($R6 = "" if directory, $R6 = "0" if file with /S=)
    
	
	#是否过滤删除  
			
	Delete "$R9"
	RMDir /r "$R9"
    RMDir "$R9"
	
	IntOp $UnInstallValue $UnInstallValue + 2
	${If} $UnInstallValue > 100
		IntOp $UnInstallValue 100 + 0
		nsNiuniuSkin::SetSliderValue "slrUnInstProgress" 100
	${Else}
		nsNiuniuSkin::SetSliderValue "slrUnInstProgress" $UnInstallValue
		Sleep 20
	${EndIf}	
	undelete:
	Push "LocateNext"	
FunctionEnd