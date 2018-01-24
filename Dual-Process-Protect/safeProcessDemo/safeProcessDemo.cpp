// safeProcessDemo.cpp : 定义控制台应用程序的入口点。
//
/**************************************************************************************
safeProcessDemo目录为主程序,TempProcess目录为临时进程,ExeProtect目录为守护进程,bin目录为编译的exe
safeProcessDemo.exe启动后通过TempProcess.exe启动ExeProtect.exe
ProcessSet.ini为配置文件 当Protect=1 safeProcessDemo.exe和ExeProtect.exe互相监控,杀一个会启一个
当Protect=0 safeProcessDemo.exe方可杀掉,杀掉safeProcessDemo.exe的同时ExeProtect.exe也自动结束
***************************************************************************************/

#include "stdafx.h"
#include "ProProcess.h"

#include <stdio.h>
#include <afx.h>
#include <afxwin.h>
#include <conio.h>
#include <afxdisp.h>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		_tprintf(_T("错误: MFC 初始化失败\n"));
		return 1;
	}
	if (!AfxOleInit())
	{
		return 1;
	}

	CProProcess::InitProProcess(_T("safeProcessDemo"));

	cout << "Enter 'q' to exit:" << endl;
	while ((_getch() != 'q') && (_getch() != 'Q'))
	{
	}
	return 0;
}

