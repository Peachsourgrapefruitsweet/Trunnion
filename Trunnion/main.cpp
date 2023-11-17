#include "Trunnion.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Trunnion w;
    w.show();
    return a.exec();
}
