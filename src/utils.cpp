#include "windows.h"
#include "utils.h"
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

// Returns the last Win32 error, in string format. Returns an empty string if there is no error.
const char *GetLastErrorAsString()
{
    // Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0)
    {
        return ""; // No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    // Ask Win32 to give us the string version of that message ID.
    // The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    const char *message(messageBuffer);

    // Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}
