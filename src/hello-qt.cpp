#include <stdio.h>
#include <QApplication>
#include "utils.h"
#include "MainWindow.h"

int main(int argc, char **argv)
{

    // don't need to load qt5 dll libraries anymore somehow? (shrugs)
    /*int loadResult = loadLibraries();
    if (loadResult != 0)
    {
        return 1;
    }*/

    printf("hello world\n"); // needs c runtime libraries

    // construct a qt5 application
    QApplication app(argc, argv);
    // construct a qt window class
    MainWindow w;
    w.show();

    // opens the window and yields the window to the user closing the window
    // exits the application and this program stops
    return app.exec();
}
