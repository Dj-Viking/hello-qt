#include <stdio.h>
#include "windows.h"
#include "windef.h"
#include "libloaderapi.h"
#include <QApplication>
#include "winbase.h"

int main(int argc, char **argv)
{
    HMODULE hLib = LoadLibraryExA("Qt5Widgets.dll", NULL, NULL);
    if (!hLib)
    {
        DWORD error = GetLastError();
        wprintf(L"Could not load Qt5Widgets.dll, Error #%d.\n", error);
        return 1;
    }

    int something = 0;
    // QApplication app(argc, argv);

    printf("hello world\n");

    return 0;
}
