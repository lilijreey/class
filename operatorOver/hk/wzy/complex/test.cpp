#include <iostream>
#include "complex.h"

int main()
{
	Complex z1(4,3);
	z1.Show();
	std::cout << "z1="<< z1 <<std::endl;
	Complex z2(4,-3);
	z2.Show();
	std::cout << "z2="<< z2 <<std::endl;
	Complex z3(0,3);
	z3.Show();
	std::cout << "z3="<< z3 <<std::endl;
	Complex z4(1,0);
	z4.Show();
	std::cout << "z4="<< z4 <<std::endl;
	Complex z5(0,5);
	z5.Show();
	std::cout << "z5="<< z5 <<std::endl;
	Complex z6(0,0);
	z6.Show();
	std::cout << "z6="<< z6 <<std::endl;
	
	(z1 + z2).Show();
	(z1 - z2).Show();
	(z1 * z1).Show();
	(z1 * z2).Show();
	std::cout << "|z1| = " 
			  << z1.GetLenth() << std::endl;
	z1.Conjugate().Show();
	z2.Conjugate().Show();
	
	return 0;
}