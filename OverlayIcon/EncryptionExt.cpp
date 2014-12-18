// EncryptionExt.cpp : CEncryptionExt µÄÊµÏÖ

#include "stdafx.h"
#include "EncryptionExt.h"
# include "dllmain.h"


// CEncryptionExt

STDMETHODIMP CEncryptionExt::GetOverlayInfo(
	PWSTR pwszIconFile, int cchMax, int *pIndex, DWORD *pdwFlags)
{
	WCHAR *buff = new WCHAR[cchMax];
	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), buff, cchMax);

	WCHAR *nChar = wcsrchr(buff, L'\\');
	if (nChar != NULL)
	{
		wcscpy_s(nChar, cchMax - wcslen(buff), L"\\icon\\encryption.ico");
		wcscpy_s(pwszIconFile, cchMax, buff);
	}

	*pIndex = 0;

	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;
	
	free(buff);
	//USES_CONVERSION;
	//log("CEncryptionExt::GetOverlayInfo");
	//log(W2A(pwszIconFile));
	return S_OK;
}
STDMETHODIMP CEncryptionExt::GetPriority(
	int *pPriority)
{
	*pPriority = 0;
	return S_OK;
	//log("CEncryptionExt::GetPriority");
}
STDMETHODIMP CEncryptionExt::IsMemberOf(
	PCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT hRef = S_FALSE;

	wchar_t* fileClass = _wcsdup(wcsrchr(pwszPath, '.'));
	if (fileClass != NULL)
	{
		if (_wcsicmp(fileClass, L".mx") == 0)
		{
			hRef = S_OK;
			//log("CEncryptionExt::IsMemberOf S_OK");
		}
	}

	//USES_CONVERSION;
	//log("CEncryptionExt::IsMemberOf");
	//log(W2A(fileClass));

	free(fileClass);
	return hRef;
}
