#include <stdio.h>
#include <QApplication>
#include "utils.h"
#include "MainWindow.h"

int main(int argc, char **argv)
{

    int loadResult = loadLibraries();
    if (loadResult != 0)
    {
        return 1;
    }

    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();
}
