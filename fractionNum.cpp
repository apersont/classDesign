#include<iostream>
#include "fractionNum.h"

int gcd(int a, int b);//����a,b���������
fractionNum::fractionNum() {
	molecule = 1;
	denominator = 1;
}//Ĭ�Ϲ���Ϊֵ��1��������
fractionNum::fractionNum(int a, int b) {
	if (b == 0) {
		std::cout << "��ĸ����Ϊ0������������" << std::endl;
		molecule = 1;
		denominator = 1;
	}
	else {
		molecule = a;
		denominator = b;
		better();
	}
}//����a/b�ķ���������ĸΪ�����׳����󲢹���ֵ��1��������
fractionNum::~fractionNum() {}//��������
fractionNum::fractionNum(fractionNum& p) {
	molecule = p.molecule;
	denominator = p.denominator;
}//���ƹ��캯��
fractionNum fractionNum::operator+(fractionNum addNum) {
	fractionNum result;//����һ�������������Ա㷵��
	result.molecule = molecule * addNum.denominator + denominator * addNum.molecule;//���Ӵ�����
	result.denominator = denominator * addNum.denominator;//��ĸ������
	result.better();//�Ż�����
	return result;//��������������
}//���غ���һ������������ļӷ�����
fractionNum fractionNum::operator-(fractionNum addNum) {
	fractionNum result;//����һ�������������Ա㷵��
	result.molecule = molecule * addNum.denominator - denominator * addNum.molecule;//���Ӵ�����
	result.denominator = denominator * addNum.denominator;//��ĸ������
	result.better();//�Ż�����
	return result;//��������������
}//���غ���һ������������ļ�������
fractionNum fractionNum::operator*(fractionNum addNum) {
	fractionNum result;//����һ�������������Ա㷵��
	result.molecule = molecule * addNum.molecule;//���Ӵ�����
	result.denominator = denominator * addNum.denominator;//��ĸ������
	result.better();//�Ż�����
	return result;//����ʵ������
}//���غ���һ������������ĳ˷�����
fractionNum fractionNum::operator/(fractionNum addNum) {
	fractionNum result;//����һ�������������Ա㷵��
	result.molecule = molecule * addNum.denominator;//���Ӵ�����
	result.denominator = denominator * addNum.molecule;//��ĸ������
	result.better();//�Ż�����
	return result;//����ʵ������
}//���غ���һ������������ĳ�������
bool fractionNum::operator==(fractionNum addNum) {
	bool result = (molecule == addNum.molecule && denominator == addNum.denominator);
	//���첼�����ͱ����������ӷ�ĸ�Ƿ�һ�������������漰ʵ������ı�ĳ��϶��ѱ���Ϊ������ֱ�ӱȽ�
	return result;//���ؽ��
}//�����ж������������Ƿ����
void fractionNum::better() {
	int temp = gcd(molecule, denominator);//��ȡ���ӷ�ĸ�������
	molecule = molecule / temp;
	denominator = denominator / temp;//ͬʱ���������ʹ���ӷ�ĸ����
	if (denominator < 0) {
		molecule = molecule * -1;
		denominator = denominator * -1;
	}//��鸺�Ų�Ų������
}//ʹ�������
rationalNum fractionNum::changClass() const {
	rationalNum reslut(getNum());//����������С��ֵ����ʵ������
	return reslut;//����ʵ������
}//��������ת��Ϊʵ��
double fractionNum::getNum() const {
	return static_cast<double>(molecule) / static_cast<double>(denominator);
	//�����ӷ�ĸǿ��ת��Ϊdouble���ͽ�������
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