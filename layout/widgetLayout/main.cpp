#include "widgetlayout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widgetLayout w;
    w.show();

    return a.exec();
}
