#include "mydata.h"



MyData::MyData(QObject *parent):QObject(parent)
{
    // 第一关
    int array1[4][4] = {
        {1,1,1,1},
        {1,1,0,1},
        {1,0,0,0},
        {1,1,0,1}
    };
    QVector<QVector<int>> v;
    for(int i=0; i<4; i++)
    {
        QVector<int> v1;
        for(int j=0; j<4; j++)
        {
            v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }
    mmap.insert(1,v);
    v.clear();
    //第2关
        int array2[4][4] ={
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1},
            {1,1,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array2[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(2,v);
        v.clear();
        //第3关
        int array3[4][4] ={
            {0,1,1,1},
            {1,1,0,1},
            {1,0,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array3[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(3,v);
        v.clear();
        //第4关
        int array4[4][4] ={
            {1,0,1,1},
            {1,1,1,1},
            {1,0,1,0},
            {0,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array4[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(4,v);
        v.clear();
        //第5关
        int array5[4][4] ={
            {1,1,0,1},
            {1,1,1,1},
            {1,0,1,0},
            {1,1,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array5[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(5,v);
        v.clear();
        //第6关
        int array6[4][4] ={
            {0,1,0,1},
            {1,1,0,1},
            {1,0,1,1},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array6[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(6,v);
        v.clear();
        //第7关
        int array7[4][4] ={
            {0,1,0,1},
            {1,1,0,1},
            {1,0,1,0},
            {1,1,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array7[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(7,v);
        v.clear();
        //第8关
        int array8[4][4] ={
            {0,1,0,1},
            {1,1,0,1},
            {0,0,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array8[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(8,v);
        v.clear();
        //第9关
        int array9[4][4] ={
            {0,1,0,1},
            {1,1,1,1},
            {1,0,1,0},
            {0,0,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array9[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(9,v);
        v.clear();
        //第10关
        int array10[4][4] ={
            {1,1,1,1},
            {1,1,0,1},
            {1,0,1,1},
            {1,1,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array10[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(10,v);
        v.clear();
        //第11关
        int array11[4][4] ={
            {1,1,1,1},
            {1,1,0,1},
            {1,1,1,1},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array11[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(11,v);
        v.clear();
        //第12关
        int array12[4][4] ={
            {1,1,1,1},
            {1,1,1,1},
            {1,0,1,0},
            {1,0,1,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array12[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(12,v);
        v.clear();
        //第13关
        int array13[4][4] ={
            {1,0,0,1},
            {1,1,0,1},
            {1,0,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array13[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(13,v);
        v.clear();
        //第14关
        int array14[4][4] ={
            {1,0,1,1},
            {0,1,0,1},
            {0,1,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array14[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(14,v);
        v.clear();
        //第15关
        int array15[4][4] ={
            {1,1,0,1},
            {0,1,0,1},
            {0,1,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array15[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(15,v);
        v.clear();
        //第16关
        int array16[4][4] ={
            {1,1,0,1},
            {1,0,1,1},
            {1,0,0,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array16[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(16,v);
        v.clear();
        //第17关
        int array17[4][4] ={
            {0,1,1,1},
            {1,0,1,1},
            {1,1,1,0},
            {1,1,0,1}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array17[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(17,v);
        v.clear();
        //第18关
        int array18[4][4] ={
            {0,1,1,1},
            {1,0,1,1},
            {1,1,0,1},
            {1,1,1,0}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array18[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(18,v);
        v.clear();
        //第19关
        int array19[4][4] ={
            {0,1,1,0},
            {1,0,0,1},
            {1,0,0,1},
            {0,1,1,0}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array19[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(19,v);
        v.clear();
        //第20关
        int array20[4][4] ={
            {0,1,1,0},
            {1,0,1,0},
            {0,1,0,1},
            {1,1,1,0}
        };

        for(int i =0 ; i<4 ;i++)
        {
            QVector<int>v1;
            for(int j =0; j<4;j++)
            {
                v1.push_back(array20[i][j]);
            }
            v.push_back(v1);
        }
        mmap.insert(20,v);
        v.clear();
}
