// DecryptionExt.cpp : CDecryptionExt µÄÊµÏÖ

#include "stdafx.h"
#include "DecryptionExt.h"
# include "dllmain.h"

// CDecryptionExt

STDMETHODIMP CDecryptionExt::GetOverlayInfo(
	PWSTR pwszIconFile, int cchMax, int *pIndex, DWORD *pdwFlags)
{
	WCHAR *buff = new WCHAR[cchMax];
	GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), buff, cchMax);

	WCHAR *nChar = wcsrchr(buff, L'\\');
	if (nChar != NULL)
	{
		wcscpy_s(nChar, cchMax - wcslen(buff), L"\\icon\\decryption.ico");
		wcscpy_s(pwszIconFile, cchMax, buff);
	}

	*pIndex = 0;

	*pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

	free(buff);
	//USES_CONVERSION;
	//log("CDecryptionExt::GetOverlayInfo");
	//log(W2A(pwszIconFile));
	return S_OK;
}
STDMETHODIMP CDecryptionExt::GetPriority(
	int *pPriority)
{
	*pPriority = 0;
	//log("CDecryptionExt::GetPriority");
	return S_OK;
}
STDMETHODIMP CDecryptionExt::IsMemberOf(
	PCWSTR pwszPath, DWORD dwAttrib)
{
	HRESULT hRef = S_FALSE;

	wchar_t* fileClass = _wcsdup(wcsrchr(pwszPath, '.'));
	if (fileClass != NULL)
	{
		if (_wcsicmp(fileClass, L".xm") == 0)
		{
			hRef = S_OK;
			//log("CDecryptionExt::IsMemberOf S_OK");
		}
	}

	//USES_CONVERSION;
	//log("CDecryptionExt::IsMemberOf");
	//log(W2A(fileClass));

	free(fileClass);
	return hRef;
}