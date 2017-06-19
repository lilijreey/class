#include <iostream>
#include <cstdio>
#include "head.h"

//复数类的四则运算
int main()
{
	Fushu a(10);
	Fushu b(20);
	Fushu tmp1(a+b);
	tmp1.Show();
	Fushu tmp2(a-b);
	tmp2.Show();
	Fushu tmp3(a*b);
	tmp3.Show();
	Fushu tmp4(a/b);
	tmp4.Show();
	return 0;
}




















































































































