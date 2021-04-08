#include "videogame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    videogame w;
    w.show();

    return a.exec();
}
