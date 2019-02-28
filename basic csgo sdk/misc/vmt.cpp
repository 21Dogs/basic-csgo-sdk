#include "vmt.h"


bool VMTHook::bInitialize(PDWORD* ppdwClassBase)
{
	m_ppdwClassBase = ppdwClassBase;
	m_pdwOldVMT = *ppdwClassBase;
	m_dwVMTSize = dwGetVMTCount(*ppdwClassBase);
	m_pdwNewVMT = new DWORD[m_dwVMTSize];
	memcpy(m_pdwNewVMT, m_pdwOldVMT, sizeof(DWORD) * m_dwVMTSize);
	*ppdwClassBase = m_pdwNewVMT;
	return true;
}
bool VMTHook::bInitialize(PDWORD** pppdwClassBase) // fix for pp
{
	return bInitialize(*pppdwClassBase);
}

void VMTHook::UnHook(void)
{
	if (m_ppdwClassBase)
	{
		*m_ppdwClassBase = m_pdwOldVMT;
	}
}

void VMTHook::ReHook(void)
{
	if (m_ppdwClassBase)
	{
		*m_ppdwClassBase = m_pdwNewVMT;
	}
}

int VMTHook::iGetFuncCount(void)
{
	return (int)m_dwVMTSize;
}

DWORD VMTHook::dwGetMethodAddress(int Index)
{
	if (Index >= 0 && Index <= (int)m_dwVMTSize && m_pdwOldVMT != NULL)
	{
		return m_pdwOldVMT[Index];
	}
	return NULL;
}

PDWORD VMTHook::pdwGetOldVMT(void)
{
	return m_pdwOldVMT;
}

DWORD VMTHook::dwHookMethod(DWORD dwNewFunc, unsigned int iIndex)
{
	if (m_pdwNewVMT && m_pdwOldVMT && iIndex <= m_dwVMTSize && iIndex >= 0)
	{
		m_pdwNewVMT[iIndex] = dwNewFunc;
		return m_pdwOldVMT[iIndex];
	}

	return NULL;
}


DWORD VMTHook::dwGetVMTCount(PDWORD pdwVMT)
{
	DWORD dwIndex = 0;

	for (dwIndex = 0; pdwVMT[dwIndex]; dwIndex++)
	{
		if (IsBadCodePtr((FARPROC)pdwVMT[dwIndex]))
		{
			break;
		}
	}
	return dwIndex;
}
