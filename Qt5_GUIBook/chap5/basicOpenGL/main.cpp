
#include "renderwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RenderWindow window;
    window.setTitle("Hello World!");
    window.resize(640, 480);
    window.show();

    return a.exec();
}
