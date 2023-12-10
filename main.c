#include <windows.h>
#include <commdlg.h>

extern HINSTANCE g_hInstance;

LONG ImageView_Main(HWND hwnd, LPCWSTR szFileName);

INT SHIMGVW_Main(INT argc, LPWSTR *argv)
{
    if (3 <= argc)
    {
        MessageBoxW(NULL, L"Invalid number of arguments", L"ReactOS shimgvw", MB_ICONERROR);
        return 1;
    }

    if (argc == 1)
        return ImageView_Main(NULL, NULL);

    return ImageView_Main(NULL, argv[1]);
}

INT WINAPI
WinMain(HINSTANCE  hInstance,
         HINSTANCE hPrevInstance,
         LPSTR     lpCmdLine,
         INT       nCmdShow)
{
    INT argc;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    g_hInstance = hInstance;
    INT ret = SHIMGVW_Main(argc, argv);
    LocalFree(argv);
    return ret;
}
