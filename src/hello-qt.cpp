#include <stdio.h>
#include <QApplication>
#include "LoadLibraries.h"
int main(int argc, char **argv)
{

    int loadResult = loadLibraries();
    if (loadResult != 0)
    {
        return 1;
    }

    QApplication app(argc, argv);

    printf("hello world\n");

    app.exec();

    return 0;
}
