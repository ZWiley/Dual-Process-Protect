#pragma once

typedef struct ProcessType
{
	TCHAR	strName[52];
	HANDLE	hProcess;
	HANDLE	hThread;
	DWORD	dwProcessId;
	DWORD	dwThreadId;
} ProcessType, *pProcessType;

class CProcessType
{
public:
	CProcessType();
	virtual ~CProcessType();
	int		GetCurrentProcessNumber() const { return m_nCurrentLength; }
	pProcessType GetBufferPoint(int nIndex);
	BOOL TerminateAProcess(int nIndex);
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

private:
	pProcessType	m_pProcessTypeBuffer;
	int				m_nCurrentLength;
	int				m_nBufferLength;
};