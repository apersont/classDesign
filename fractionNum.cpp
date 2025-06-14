#include<iostream>
#include "fractionNum.h"

int gcd(int a, int b);//返回a,b的最大公因数
fractionNum::fractionNum() {
	molecule = 1;
	denominator = 1;
}//默认构造为值是1的有理数
fractionNum::fractionNum(int a, int b) {
	if (b == 0) {
		std::cout << "分母不能为0，请重新输入" << std::endl;
		molecule = 1;
		denominator = 1;
	}
	else {
		molecule = a;
		denominator = b;
		better();
	}
}//构造a/b的分数，若分母为零则抛出错误并构造值是1的有理数
fractionNum::~fractionNum() {}//析构函数
fractionNum::fractionNum(fractionNum& p) {
	molecule = p.molecule;
	denominator = p.denominator;
}//复制构造函数
fractionNum fractionNum::operator+(fractionNum addNum) {
	fractionNum result;//构造一个有理数对象以便返回
	result.molecule = molecule * addNum.denominator + denominator * addNum.molecule;//分子处理方法
	result.denominator = denominator * addNum.denominator;//分母处理方法
	result.better();//优化得数
	return result;//返回有理数对象
}//重载和另一个有理数对象的加法运算
fractionNum fractionNum::operator-(fractionNum addNum) {
	fractionNum result;//构造一个有理数对象以便返回
	result.molecule = molecule * addNum.denominator - denominator * addNum.molecule;//分子处理方法
	result.denominator = denominator * addNum.denominator;//分母处理方法
	result.better();//优化得数
	return result;//返回有理数对象
}//重载和另一个有理数对象的减法运算
fractionNum fractionNum::operator*(fractionNum addNum) {
	fractionNum result;//构造一个有理数对象以便返回
	result.molecule = molecule * addNum.molecule;//分子处理方法
	result.denominator = denominator * addNum.denominator;//分母处理方法
	result.better();//优化得数
	return result;//返回实数对象
}//重载和另一个有理数对象的乘法运算
fractionNum fractionNum::operator/(fractionNum addNum) {
	fractionNum result;//构造一个有理数对象以便返回
	result.molecule = molecule * addNum.denominator;//分子处理方法
	result.denominator = denominator * addNum.molecule;//分母处理方法
	result.better();//优化得数
	return result;//返回实数对象
}//重载和另一个有理数对象的除法运算
bool fractionNum::operator==(fractionNum addNum) {
	bool result = (molecule == addNum.molecule && denominator == addNum.denominator);
	//构造布尔类型变量并检查分子分母是否一样，由于所有涉及实数对象改变的场合都已被化为最简因此直接比较
	return result;//返回结果
}//重载判断两个有理数是否相等
void fractionNum::better() {
	int temp = gcd(molecule, denominator);//获取分子分母最大公因数
	molecule = molecule / temp;
	denominator = denominator / temp;//同时除最大公因数使分子分母互质
	if (denominator < 0) {
		molecule = molecule * -1;
		denominator = denominator * -1;
	}//检查负号并挪至分子
}//使分数最简化
rationalNum fractionNum::changClass() const {
	rationalNum reslut(getNum());//依靠分数的小数值构造实数对象
	return reslut;//返回实数对象
}//将有理数转化为实数
double fractionNum::getNum() const {
	return static_cast<double>(molecule) / static_cast<double>(denominator);
	//将分子分母强制转化为double类型进行运算
}//
void fractionNum::showNum() const {
	std::cout << molecule << "/" << denominator;
}
int gcd(int a, int b) {
	int m = a % b;
	while (m) {
		a = m;
		m = b % m;
		b = a;
	}
	return b;
}