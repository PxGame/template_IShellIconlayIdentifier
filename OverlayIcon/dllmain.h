// dllmain.h : 模块类的声明。

class COverlayIconModule : public ATL::CAtlDllModuleT< COverlayIconModule >
{
public :
	DECLARE_LIBID(LIBID_OverlayIconLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OVERLAYICON, "{F8CA0C64-C458-491A-AD25-DA1A03ED1D12}")
};

extern class COverlayIconModule _AtlModule;
