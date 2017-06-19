#include <iostream>
#include <complex>

class Complex
{
	double real;
	double imaginary;
public:
	Complex(double r=0.0, double i=0.0):real(r),imaginary(i)
	{
	}
	Complex operator+(const Complex &a) const
	{
		Complex tmp;
		tmp.real = this->real + a.real;
		tmp.imaginary = this->imaginary + a.imaginary;
		return tmp;
	}
	Complex operator-(const Complex &a) const
	{
		Complex tmp;
		tmp.real = this->real - a.real;
		tmp.imaginary = this->imaginary - a.imaginary;
		return tmp;
	}
	Complex operator*(const Complex &a) const
	{
		Complex tmp;
		tmp.real = this->real*a.real - this->imaginary*a.imaginary;
		tmp.imaginary = this->real*a.imaginary + this->imaginary*a.imaginary;
		return tmp;
	}
	Complex operator/(const Complex &a) const
	{
		Complex tmp;
		tmp.real = (this->real*a.real + this->imaginary*a.imaginary) / (a.real*a.real + a.imaginary*a.imaginary);
		tmp.imaginary = (this->real*a.imaginary*(-1) + this->imaginary*a.real) / (a.real*a.real + a.imaginary*a.imaginary);
		return tmp;
	}

	friend std::ostream & operator<<(std::ostream &os, const Complex &out);
};

inline std::ostream & operator<<(std::ostream &os, const Complex &out)
{
	os << out.real << "+" << out.imaginary << "i" ;
    return os;
}

int main()
{
	Complex t1(3,4);
	Complex t2(5,6);

	Complex add = t1+t2;
	Complex sub = t2-t1;
	Complex mul = t1*t2;
	Complex div = t2/t1;

	std::cout << "add=" << add << "\n" 
		      << "sub=" << sub << "\n" 
			  << "mul=" << mul << "\n" 
			  << "div=" << div <<std::endl;

	return 0;
}