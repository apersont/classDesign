#ifndef RATIONAL_H
#define RATIONAL_H

class rationalNum
{
private:
	double trueNum;
public:
	void setNum(double nNum);
	double getNum();
	rationalNum();
	rationalNum(double a);
	~rationalNum();
	rationalNum(rationalNum& p);
};

#endif