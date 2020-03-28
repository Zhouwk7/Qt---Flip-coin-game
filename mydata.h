#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include<QMap>
#include<QVector>

class MyData : public QObject
{
    Q_OBJECT
public:
    MyData(QObject* parent = 0);
    QMap<int, QVector<QVector<int>>> mmap;
};

#endif // MYDATA_H
