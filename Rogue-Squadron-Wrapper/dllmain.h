#pragma once

#include <dsound.h>

class f_iDirectSound : public IDirectSound
{
private:
	LPDIRECTSOUND f_DirectSound;

public:
	f_iDirectSound(LPDIRECTSOUND pDirectSound) { f_DirectSound = pDirectSound; }
	f_iDirectSound() { f_DirectSound = NULL; }

	STDMETHOD(DirectSoundCreate)(LPGUID lpGuid, void** ppDS, void* pUnkOuter);
	STDMETHOD(DirectSoundEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
	STDMETHOD(DirectSoundEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
	STDMETHOD(DllCanUnloadNow)(THIS);
	STDMETHOD(DllGetClassObject)(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
	STDMETHOD(DirectSoundCaptureCreate)(LPGUID lpGUID, void** lplpDSC, void* pUnkOuter);
	STDMETHOD(DirectSoundCaptureEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
	STDMETHOD(DirectSoundCaptureEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
	STDMETHOD(GetDeviceID)(LPCGUID lpGuidSrc, LPGUID lpGuidDest);
	STDMETHOD(DirectSoundFullDuplexCreate)(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, void* pcDSCBufferDesc, void* pcDSBufferDesc, HWND hWnd, DWORD dwLevel, void** ppDSFD, void** ppDSCBuffer8, void** ppDSBuffer8, void* pUnkOuter);
	STDMETHOD(DirectSoundCreate8)(LPCGUID lpGUID, void** ppDS8, void* pUnkOuter);
	STDMETHOD(DirectSoundCaptureCreate8)(LPCGUID lpGUID, void** ppDSC8, void* pUnkOuter);
};

typedef HRESULT(WINAPI* LPWDirectSoundCreate)(LPGUID lpGuid, void** ppDS, void* pUnkOuter);
typedef HRESULT(WINAPI* LPWDirectSoundEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
typedef HRESULT(WINAPI* LPWDirectSoundEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
typedef HRESULT(WINAPI* LPWDllCanUnloadNow)();
typedef HRESULT(WINAPI* LPWDllGetClassObject)(REFCLSID rclsid, REFIID riid, LPVOID* ppv);
typedef HRESULT(WINAPI* LPWDirectSoundCaptureCreate)(LPGUID lpGUID, void** lplpDSC, void* pUnkOuter);
typedef HRESULT(WINAPI* LPWDirectSoundCaptureEnumerateA)(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext);
typedef HRESULT(WINAPI* LPWDirectSoundCaptureEnumerateW)(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext);
typedef HRESULT(WINAPI* LPWGetDeviceID)(LPCGUID lpGuidSrc, LPGUID lpGuidDest);
typedef HRESULT(WINAPI* LPWDirectSoundFullDuplexCreate)(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, void* pcDSCBufferDesc, void* pcDSBufferDesc, HWND hWnd, DWORD dwLevel, void** ppDSFD, void** ppDSCBuffer8, void** ppDSBuffer8, void* pUnkOuter);
typedef HRESULT(WINAPI* LPWDirectSoundCreate8)(LPCGUID lpGUID, void** ppDS8, void* pUnkOuter);
typedef HRESULT(WINAPI* LPWDirectSoundCaptureCreate8)(LPCGUID lpGUID, void** ppDSC8, void* pUnkOuter);


struct dsound_dll
{
	HMODULE dll;
	LPWDirectSoundCreate DirectSoundCreate;
	LPWDirectSoundEnumerateA DirectSoundEnumerateA;
	LPWDirectSoundEnumerateW DirectSoundEnumerateW;
	LPWDllCanUnloadNow DllCanUnloadNow;
	LPWDllGetClassObject DllGetClassObject;
	LPWDirectSoundCaptureCreate DirectSoundCaptureCreate;
	LPWDirectSoundCaptureEnumerateA DirectSoundCaptureEnumerateA;
	LPWDirectSoundCaptureEnumerateW DirectSoundCaptureEnumerateW;
	LPWGetDeviceID GetDeviceID;
	LPWDirectSoundFullDuplexCreate DirectSoundFullDuplexCreate;
	LPWDirectSoundCreate8 DirectSoundCreate8;
	LPWDirectSoundCaptureCreate8 DirectSoundCaptureCreate8;
} dsound;