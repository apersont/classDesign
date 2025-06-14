#ifndef FRACTIONNUM_H
#define FRACTIONNUM_H
#include "rationalNum.h"

//分数类
class fractionNum :
    public rationalNum
{
 private:
     int molecule;//分子
     int denominator;//分母
public:
    fractionNum();
    fractionNum(int a, int b);
    ~fractionNum();
    fractionNum(fractionNum& p);
    fractionNum operator+(fractionNum addNum);
    fractionNum operator-(fractionNum addNum);
    fractionNum operator*(fractionNum addNum);
    fractionNum operator/(fractionNum addNum);
    fractionNum operator+(double douNum);
    fractionNum operator-(double douNum);
    fractionNum operator*(double douNum);
    fractionNum operator/(double douNum);
    bool operator==(fractionNum addNum);
    bool operator==(double douNum);
    void better();
    rationalNum changClass() const;
    double getNum() const;
    void showNum() const;
};

#endif