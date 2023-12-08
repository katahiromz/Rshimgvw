#include <windows.h>
#include <commdlg.h>

extern HINSTANCE hInstance;

LONG WINAPI
ImageView_CreateWindow(HWND hwnd, LPCWSTR szFileName);

INT SHIMGVW_main(INT argc, LPWSTR *argv)
{
    if (3 <= argc)
    {
        MessageBoxW(NULL, L"Invalid number of arguments", L"ReactOS shimgvw", MB_ICONERROR);
        return 1;
    }

    LPWSTR filename = argv[1];
    WCHAR szFile[MAX_PATH] = { 0 };
    if (argc <= 1)
    {
        OPENFILENAMEW ofn = { sizeof(ofn) };
        ofn.lpstrFilter =
            L"Supported Image Files\0*.jpg;*.jpeg;*.jpe;*.jfif;*.png;*.gif;*.tif;*.tiff;*.bmp;*.dib\0"
            L"JPEG (*.jpg;*.jpeg;*.jpe;*.jfif)\0*.jpg;*.jpeg;*.jpe;*.jfif\0"
            L"PNG (*.png)\0*.png\0"
            L"GIF (*.gif)\0*.gif\0"
            L"TIFF (*.tif;*.tiff)\0*.tif;*.tiff\0"
            L"Bitmap Files (*.bmp;*.dib)\0*.bmp;*.dib\0";
        ofn.lpstrFile = szFile;
        ofn.nMaxFile = _countof(szFile);
        ofn.lpstrTitle = L"Open Image File";
        ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_ENABLESIZING;
        ofn.lpstrDefExt = L"png";
        if (!GetOpenFileName(&ofn))
            return 0;

        filename = szFile;
    }

    ImageView_CreateWindow(NULL, filename);
    return 0;
}

INT WINAPI
WinMain(HINSTANCE  hInst,
         HINSTANCE hPrevInst,
         LPSTR     lpCmdLine,
         INT       nCmdShow)
{
    INT argc;
    LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    hInstance = hInst;
    INT ret = SHIMGVW_main(argc, argv);
    LocalFree(argv);
    return ret;
}
