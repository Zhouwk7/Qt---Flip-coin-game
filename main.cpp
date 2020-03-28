#include "mainscene.h"

#include <QApplication>
#include "mydata.h"
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
//    MyData mydat;
//    for(int i=0; i< 4; i++)
//    {
//        for(int j=0; j<4; j++)
//        {
//            qDebug() << mydat.mmap[1][i][j] << endl;
//        }
//    }
    w.show();
    return a.exec();
}
