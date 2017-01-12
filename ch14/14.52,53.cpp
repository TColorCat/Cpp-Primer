
#include "stdafx.h"

#include<iostream>
using namespace std;
class SmallInt
{
	friend SmallInt operator+(const SmallInt& a, const SmallInt& b)//1
	{
		cout << "SmallInt's friend function +" << endl;
	}
private:
	int val;
public:
	SmallInt(int a = 0){ val = a; };
	operator int()const{ return val; }

};
struct Longdouble
{
	Longdouble operator+(const SmallInt& sl){ cout << "Longdouble's function +" << endl; }//2

};
Longdouble operator+(Longdouble& ld, double c){ cout << "longdouble+double" << endl; }//3
int _tmain(int argc, _TCHAR* argv[])
{
	SmallInt si(1);
	Longdouble ld;
	ld = si + ld;//没有相关函数，候选函数为1,3,内置+,
	ld = ld + si;//候选函数为2,3,内置函数. 使用2
	ld = ld + 2;//使用3
	double d = si + 3.14;//二义性 ：内置+运算符（si化成int），函数1（int可以化为SmallInt）
	int i = si + 1;//二义性

	return 0;
}

