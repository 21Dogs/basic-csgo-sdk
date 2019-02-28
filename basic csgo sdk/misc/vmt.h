#pragma once
#include <windows.h>

class VMTHook
{
public:

	VMTHook(void)
	{
		memset(this, 0, sizeof(VMTHook));
	}

	VMTHook(PDWORD* ppdwClassBase)
	{
		bInitialize(ppdwClassBase);
	}

	~VMTHook(void)
	{
		UnHook();
	}

	bool bInitialize(PDWORD* ppdwClassBase);

	void UnHook(void);

	int iGetFuncCount(void);

	DWORD dwGetMethodAddress(int Index);
	PDWORD pdwGetOldVMT(void);
	DWORD dwHookMethod(DWORD dwNewFunc, unsigned int iIndex);


private:

	DWORD dwGetVMTCount(PDWORD pdwVMT);
	PDWORD*	m_ppdwClassBase;
	PDWORD	m_pdwNewVMT, m_pdwOldVMT;
	DWORD	m_dwVMTSize;
}; 