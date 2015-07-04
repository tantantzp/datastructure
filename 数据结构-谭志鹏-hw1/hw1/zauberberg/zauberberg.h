#ifndef ZAUBERBERG_H
#define ZAUBERBERG_H

#include "Vector.h"
#include <iostream>

using namespace std;

struct life                              //结构数组记录生物信息，重载比较运算符便于排序操作 
{
    long height;
    char health;
    life():height(-1),health('*'){}
    life(int hei,char heal):height(hei),health(heal){}
    bool operator < (life& l);
    bool operator > (life& l);
    bool operator >=(life& l);
    bool operator <=(life& l);
    friend ostream& operator<<(ostream&,life&);
    friend istream& operator>>(istream&,life&);
};

class Berg:public Vector<life>             //Berg从Vector<life>继承，使用向量的elem顺序记录山中生物信息 
{
public:
    int illNum;
    int healthNum;
    int lifeNum;
    long maxheight;
    int* healHeight;
    int* illHeight;
protected:
    int QSortPart(int low,int high);
public:
    Berg(int N,long max,int cap=10):Vector<life>::Vector(cap){illNum=-1;healthNum=-1;lifeNum=N;maxheight=max;}

    void output(int lo, int hi);
    void output(){output(0,size);}

    void QSort(int low,int high);
    void QSort(){QSort(0,size-1);}
    void init();
    void caculate(double, double);
};




#include "zauberberg_implenentation.h"

#endif // ZAUBERBERG_H
