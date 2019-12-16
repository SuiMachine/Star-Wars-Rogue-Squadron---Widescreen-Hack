#include <Windows.h>
#include "dllmain.h"
#include "../WidescreenHackLib/PerspectiveCorrection.h"

PerspectiveCorrection* perspectiveCorrection;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//Initialize the hack
		HMODULE mod = GetModuleHandle(NULL);
		perspectiveCorrection = new PerspectiveCorrection("");

		char moduleName[MAX_PATH];
		GetModuleFileName(mod, moduleName, MAX_PATH);

		std::string str = (std::string)moduleName;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		auto filename = str.substr(str.find_last_of('\\') + 1);
		if (filename.find("rogue") != std::string::npos && filename.find("squadron") != std::string::npos)
			perspectiveCorrection->FixStuff();

		//Set pointers to wrapper
		char path[MAX_PATH];
		GetSystemDirectory(path, MAX_PATH);
		strcat_s(path, "\\dsound.dll");

		dsound.dll = LoadLibrary(path);
		dsound.DirectSoundCreate = (LPWDirectSoundCreate)GetProcAddress(dsound.dll, "DirectSoundCreate");
		dsound.DirectSoundEnumerateA = (LPWDirectSoundEnumerateA)GetProcAddress(dsound.dll, "DirectSoundEnumerateA");
		dsound.DirectSoundEnumerateW = (LPWDirectSoundEnumerateW)GetProcAddress(dsound.dll, "DirectSoundEnumerateW");
		dsound.DllCanUnloadNow = (LPWDllCanUnloadNow)GetProcAddress(dsound.dll, "DllCanUnloadNow");
		dsound.DllGetClassObject = (LPWDllGetClassObject)GetProcAddress(dsound.dll, "DllGetClassObject");
		dsound.DirectSoundCaptureCreate = (LPWDirectSoundCaptureCreate)GetProcAddress(dsound.dll, "DirectSoundCaptureCreate");
		dsound.DirectSoundCaptureEnumerateA = (LPWDirectSoundCaptureEnumerateA)GetProcAddress(dsound.dll, "DirectSoundCaptureEnumerateA");
		dsound.DirectSoundCaptureEnumerateW = (LPWDirectSoundCaptureEnumerateW)GetProcAddress(dsound.dll, "DirectSoundCaptureEnumerateW");
		dsound.GetDeviceID = (LPWGetDeviceID)GetProcAddress(dsound.dll, "GetDeviceID");
		dsound.DirectSoundFullDuplexCreate = (LPWDirectSoundFullDuplexCreate)GetProcAddress(dsound.dll, "DirectSoundFullDuplexCreate");
		dsound.DirectSoundCreate8 = (LPWDirectSoundCreate8)GetProcAddress(dsound.dll, "DirectSoundCreate8");
		dsound.DirectSoundCaptureCreate8 = (LPWDirectSoundCaptureCreate8)GetProcAddress(dsound.dll, "DirectSoundCaptureCreate8");
	}

    return TRUE;
}

HRESULT WINAPI DirectSoundCreate(LPGUID lpGuid, void** ppDS, void* pUnkOuter)
{
	HRESULT hr = dsound.DirectSoundCreate(lpGuid, ppDS, pUnkOuter);
	return hr;
}

HRESULT WINAPI DirectSoundEnumerateA(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext)
{
	HRESULT hr = dsound.DirectSoundEnumerateA(lpDSEnumCallback, lpContext);
	return hr;
}

HRESULT WINAPI DirectSoundEnumerateW(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext)
{
	HRESULT hr = dsound.DirectSoundCaptureEnumerateW(lpDSEnumCallback, lpContext);
	return hr;
}

HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return dsound.DllGetClassObject(rclsid, riid, ppv);
}

HRESULT WINAPI DirectSoundCaptureCreate(LPGUID lpGUID, void** lplpDSC, void* pUnkOuter)
{
	return dsound.DirectSoundCaptureCreate(lpGUID, lplpDSC, pUnkOuter);
}

HRESULT WINAPI DirectSoundCaptureEnumerateA(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext)
{
	return dsound.DirectSoundCaptureEnumerateA(lpDSEnumCallback, lpContext);
}

HRESULT WINAPI DirectSoundCaptureEnumerateW(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext)
{
	return dsound.DirectSoundCaptureEnumerateW(lpDSEnumCallback, lpContext);
}

HRESULT WINAPI GetDeviceID(LPCGUID lpGuidSrc, LPGUID lpGuidDest)
{
	return dsound.GetDeviceID(lpGuidSrc, lpGuidDest);
}
HRESULT WINAPI DirectSoundFullDuplexCreate(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, void* pcDSCBufferDesc, void* pcDSBufferDesc, HWND hWnd, DWORD dwLevel, void** ppDSFD, void** ppDSCBuffer8, void** ppDSBuffer8, void* pUnkOuter)
{
	return dsound.DirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter);
}

HRESULT WINAPI DirectSoundCreate8(LPCGUID lpGUID, void** ppDS8, void* pUnkOuter)
{
	return dsound.DirectSoundCreate8(lpGUID, ppDS8, pUnkOuter);
}

HRESULT WINAPI DirectSoundCaptureCreate8(LPCGUID lpGUID, void** ppDSC8, void* pUnkOuter)
{
	return dsound.DirectSoundCaptureCreate8(lpGUID, ppDSC8, pUnkOuter);
}

HRESULT WINAPI DllCanUnloadNow()
{
	return dsound.DllCanUnloadNow();
}