#include "rationalNum.h"
void rationalNum::setNum(double nNum) {
	trueNum = nNum;
}
double rationalNum::getNum() {
	return trueNum;
}
rationalNum::rationalNum() {
	trueNum = 0;
}
rationalNum::rationalNum(double a) {
	trueNum = a;
}
rationalNum::~rationalNum() {
}
rationalNum::rationalNum(rationalNum& p) {
	trueNum = p.trueNum;
}