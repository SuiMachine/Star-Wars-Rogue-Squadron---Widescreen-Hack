#include <windows.h>
#include <detours.h>
#include "PerspectiveCorrection.h"

PerspectiveCorrection* perspectiveCorrection;

static HWND(__stdcall* TrueCreateWindowEx)(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) = CreateWindowEx;
HWND __stdcall DetourCreateWindowEx(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	auto result = TrueCreateWindowEx(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	if (strstr(lpWindowName, "ROGUE") != 0)
	{
		perspectiveCorrection->FixStuff();
	}

	return result;
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		HMODULE mod = GetModuleHandle(NULL);
		perspectiveCorrection = new PerspectiveCorrection();

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)TrueCreateWindowEx, DetourCreateWindowEx);
		DetourTransactionCommit();

	}
	else if (reason == DLL_PROCESS_DETACH) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)TrueCreateWindowEx, DetourCreateWindowEx);
		DetourTransactionCommit();
	}
	return TRUE;
}