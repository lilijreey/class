#include <iostream>
#include <cmath>
#include "complex.h"

//构造函数
Complex::Complex(double real,double image):
_real(real),_image(image)
{}
	
//双目运算符+号重载
const Complex Complex::operator+(const Complex& right)
{
	Complex tmp;
	tmp._real = _real + right._real;
	tmp._image = _image + right._image;
	return tmp;
}
	
//双目运算符-号重载
const Complex Complex::operator-(const Complex& right)
{
	Complex tmp;
	tmp._real = _real - right._real;
	tmp._image = _image - right._image;
	return tmp;
}
	
//双目运算符*号重载
const Complex Complex::operator*(const Complex& right)
{
	Complex tmp;
	tmp._real = _real * right._real - _image * right._image;
	tmp._image = _real * right._image + _image * right._real;
	return tmp;
}	
	
//双目运算符/号重载
const Complex Complex::operator/(const Complex& right)
{
	Complex tmp;
	tmp._real = (_real * right._real + _image * right._image)/(_real * _real + _image * _image);
	tmp._image = (_image * right._real - _real * right._image)/(_real * _real + _image * _image);
	return tmp;
}
	
//复数的长度，即模长
double Complex::GetLenth() const
{
	return sqrt(_real * _real + _image * _image);
}	
	
//求一个复数对象的共轭
const Complex Complex::Conjugate() const
{
	Complex tmp;
	tmp._real = _real;
	tmp._image = -_image;
	return tmp;
}
	
//输出 << 的重载，声明为Comolex类的友元函数
std::ostream & operator<<(std::ostream &os,const Complex& c);
	
//打印一个复数对象，以 a+bi 的形式
void Complex::Show() const
{
	if(_image == 0) //_image == 0
	{
		std::cout<< _real << std::endl;
	}
	else if(_real == 0) //_image != 0,_real == 0
	{
		std::cout << _image << "i" <<std::endl;
	}
		
	else if(_image > 0)//_image > 0
	{
		std::cout<< _real << "+" << _image << "i" <<std::endl;
	}
	else//_image < 0
	{
		std::cout<< _real << _image << "i" <<std::endl;
	}
}							

//输出的重载，以 a+bi 的形式输出一个复数对象
std::ostream & operator<<(std::ostream &os,const Complex &c)
{
	if(c._image == 0) //_image == 0
	{
		os << c._real << std::endl;
	}
	else if(c._real == 0) //_image != 0,_real == 0
	{
		os << c._image << "i" <<std::endl;
	}
		
	else if(c._image > 0)//_image > 0
	{
		os << c._real << "+" << c._image << "i" <<std::endl;
	}
	else//_image < 0
	{
		os << c._real << c._image << "i" <<std::endl;
	}
	return os;
}