// DecryptionExt.h : CDecryptionExt ������

#pragma once
#include "resource.h"       // ������
#include "OverlayIcon_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CDecryptionExt

class ATL_NO_VTABLE CDecryptionExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDecryptionExt, &CLSID_DecryptionExt>,
	public IDispatchImpl<IDecryptionExt, &IID_IDecryptionExt, &LIBID_OverlayIconLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellIconOverlayIdentifier
{
public:
	CDecryptionExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DECRYPTIONEXT)


BEGIN_COM_MAP(CDecryptionExt)
	COM_INTERFACE_ENTRY(IDecryptionExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(GetOverlayInfo)(PWSTR pwszIconFile, int cchMax, int *pIndex, DWORD *pdwFlags);
	STDMETHOD(GetPriority)(int *pPriority);
	STDMETHOD(IsMemberOf)(PCWSTR pwszPath, DWORD dwAttrib);
};

OBJECT_ENTRY_AUTO(__uuidof(DecryptionExt), CDecryptionExt)
