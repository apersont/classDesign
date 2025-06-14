#ifndef FRACTIONNUM_H
#define FRACTIONNUM_H
#include "rationalNum.h"

//������
class fractionNum :
    public rationalNum
{
 private:
     int molecule;//����
     int denominator;//��ĸ
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