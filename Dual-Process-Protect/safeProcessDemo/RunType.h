#pragma once

#include <stdio.h>
#include <minwindef.h>
#include <wtypes.h>
#include <afx.h>

typedef struct RunType
{
	BOOL	bRuned;
	BOOL	bAutoRun;
	int		nShowMode;
	int		nHour;
	int		nMinute;
	BOOL	bRunWithTime;
	UINT	uHotKeyID;
	UINT	uHotKeyVk;
	UINT	uHotKeyFlag;
	TCHAR	strFilePath[256];
	TCHAR	strName[52];
} RunType, *pRunType;

typedef struct SuperType
{
	BOOL bEnable;
	BOOL bPrompt;
	int nHour;
	int nMinute;
	int nTask;
	int nAheadMinutes;
	//	DWORD dwReserve;
} SuperType, *pSuperType;


class CRunType
{
public:
	CRunType();
	virtual ~CRunType();

	BOOL RegisterAllItemsHotKey();
	void UnRegisterAllItemsHotKey();

	int SearchTheID(UINT uID);
	void PostRunWithMessage();

	BOOL IsBufferEmpty() { return (m_nCurrentLength == 0); }
	int	 GetCurrentLength() const { return m_nCurrentLength; }

	void ThreadChecking();
	void GetMainWndHandle(HWND hWnd)
	{
		ASSERT(IsWindow(hWnd));
		m_hMainWnd = hWnd;
	}

	pSuperType GetSuperTypeBufferHead()  { return m_stSuperTypeBuffer; }

	int GetSuperTypeTask(int nIndex);
private:
	BOOL IsIndexValid(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_nCurrentLength)
		{
			ASSERT(0);
			return FALSE;
		}
		return TRUE;
	}

	void SetHotKeyName(LPTSTR source, WORD vk, WORD flag);
private:
	pRunType	m_pRunTypeBuffer;
	SuperType	m_stSuperTypeBuffer[7];
	int			m_nBufferLength;
	int			m_nCurrentLength;
	HWND		m_hMainWnd;

};

