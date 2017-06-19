#include <iostream>
#include <cstdio>

using namespace std;
class Fushu
{
private:
	long i;
public:
	Fushu(long i)
	{
		this->i=i;
	}
	void Show()
	{
		cout << i << endl;
	}
	/*Fushu& operator=(Fushu &a)
	{
		this->i=a.i;
		return *this;
	}*/
	friend Fushu operator+(Fushu &a,Fushu &b);
	friend Fushu operator-(Fushu &a,Fushu &b);
	friend Fushu operator*(Fushu &a,Fushu &b);
	friend Fushu operator/(Fushu &a,Fushu &b);
	
};

Fushu operator+(Fushu &a,Fushu &b)
{
	Fushu tmp(a.i+b.i);
	return tmp;
}

Fushu operator-(Fushu &a,Fushu &b)
{
	Fushu tmp(a.i-b.i);
	return tmp;
}

Fushu operator*(Fushu &a,Fushu &b)
{
	Fushu tmp(a.i*b.i);
	return tmp;
}

Fushu operator/(Fushu &a,Fushu &b)
{
	Fushu tmp(a.i/b.i);
	return tmp;
}
