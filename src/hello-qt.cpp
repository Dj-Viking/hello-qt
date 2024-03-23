#include <stdio.h>
#include "windows.h"
#include "windef.h"
#include "libloaderapi.h"
#include <QApplication>
#include "winbase.h"
#include "GetLastErrorAsString.h"

int main(int argc, char **argv)
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

    QApplication app(argc, argv);

    printf("hello world\n");

    app.exec();

    return 0;
}
