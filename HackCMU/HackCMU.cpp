// HackCMU.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HackCMU.h"
#include <fstream>
#include <string>
#include <vector>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

CComPtr<IShellWindows> g_spWindows;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

std::vector<std::wstring> DumpWindows();

class CCoInitialize {
public:
	CCoInitialize() : m_hr(CoInitialize(NULL)) { }
	~CCoInitialize() { if (SUCCEEDED(m_hr)) CoUninitialize(); }
	operator HRESULT() const { return m_hr; }
	HRESULT m_hr;
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	CCoInitialize init;
	g_spWindows.CoCreateInstance(CLSID_ShellWindows);

	std::vector<std::wstring> blacklist;
	blacklist.push_back(L"www.facebook.com");
	blacklist.push_back(L"www.reddit.com");

	while (true) {
		std::wstring sadUrl = L"meme-tdogt34.c9users.io/todo.php?sad";
		bool sad = false;

		std::wstring o;
		auto urls = DumpWindows();
		for (std::wstring url : urls) {
			for (std::wstring blocked : blacklist) {
				if (url.find(sadUrl) != std::string::npos) {
					sad = false;
					//break;
				}
				if (url.find(blocked) != std::string::npos) {
					sad = true;
				}
			}
			o += url;
		}

		if (sad) {
			//system("\"%ProgramFiles%\\Internet Explorer\\iexplore.exe\"");
			ShellExecute(0, 0, L"https://meme-tdogt34.c9users.io/todo.php?sad", 0, 0, SW_SHOW);
		}

		Sleep(1000);
	}

	g_spWindows.Release();

    // Initialize global strings
    /*LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HACKCMU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HACKCMU));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;*/
	//

	return 0;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HACKCMU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HACKCMU);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//i
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

HRESULT GetLocationFromView(IShellBrowser *psb,
	PWSTR *ppszLocation)
{
	HRESULT hr;

	*ppszLocation = nullptr;

	CComPtr<IShellView> spsv;
	hr = psb->QueryActiveShellView(&spsv);
	if (FAILED(hr)) return hr;

	CComQIPtr<IPersistIDList> sppidl(spsv);
	if (!sppidl) return E_FAIL;

	CComHeapPtr<ITEMIDLIST_ABSOLUTE> spidl;
	hr = sppidl->GetIDList(&spidl);
	if (FAILED(hr)) return hr;

	CComPtr<IShellItem> spsi;
	hr = SHCreateItemFromIDList(spidl, IID_PPV_ARGS(&spsi));
	if (FAILED(hr)) return hr;

	hr = spsi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING,
		ppszLocation);
	return hr;
}

HRESULT GetLocationFromBrowser(IUnknown *punk,
	PWSTR *ppszLocation)
{
	HRESULT hr;

	CComQIPtr<IWebBrowser2> spwb2(punk);
	if (!spwb2) return E_FAIL;

	CComBSTR sbsLocation;
	hr = spwb2->get_LocationURL(&sbsLocation);
	if (FAILED(hr)) return hr;

	return SHStrDupW(sbsLocation, ppszLocation);
}

HRESULT GetBrowserInfo(IUnknown *punk, HWND *phwnd,
	PWSTR *ppszLocation)
{
	HRESULT hr;

	CComPtr<IShellBrowser> spsb;
	hr = IUnknown_QueryService(punk, SID_STopLevelBrowser,
		IID_PPV_ARGS(&spsb));
	if (FAILED(hr)) return hr;

	hr = spsb->GetWindow(phwnd);
	if (FAILED(hr)) return hr;

	hr = GetLocationFromView(spsb, ppszLocation);
	if (SUCCEEDED(hr)) return hr;

	return GetLocationFromBrowser(punk, ppszLocation);
}

std::vector<std::wstring> DumpWindows()
{
	CComPtr<IUnknown> spunkEnum;
	HRESULT hr = g_spWindows->_NewEnum(&spunkEnum);
	if (FAILED(hr)) return std::vector<std::wstring>();

	std::vector<std::wstring> ret;

	CComQIPtr<IEnumVARIANT> spev(spunkEnum);
	for (CComVariant svar;
		spev->Next(1, &svar, nullptr) == S_OK;
		svar.Clear()) {
		if (svar.vt != VT_DISPATCH) continue;

		HWND hwnd;
		CComHeapPtr<WCHAR> spszLocation;
		if (FAILED(GetBrowserInfo(svar.pdispVal, &hwnd,
			&spszLocation))) continue;

		ret.push_back(static_cast<PCWSTR>(spszLocation));
	}

	return ret;
}

