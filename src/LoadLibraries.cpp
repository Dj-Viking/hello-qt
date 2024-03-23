#include "windows.h"
#include "GetLastErrorAsString.h"
#include <stdio.h>
int loadLibraries(void)
{
    DLL_DIRECTORY_COOKIE dircookie = AddDllDirectory(L"\\..\\..\\..\\qt5-build\\qtbase\\lib");
    if (!dircookie)
    {
        const char *msg = GetLastErrorAsString();
        printf("Could not add directory qt5base\\bin, Error %s.\n", msg);
        return 1;
    }
    HMODULE hLib = LoadLibraryExA("Qt5Widgets.dll", NULL, NULL);
    if (!hLib)
    {
        const char *msg = GetLastErrorAsString();
        printf("Could not load Qt5Widgets.dll, Error %s.\n", msg);
        return 1;
    }

    return 0;
}