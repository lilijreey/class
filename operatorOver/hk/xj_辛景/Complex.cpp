#include<iostream>
using namespace std;

class Complex
{
private:
	double real;  //复数实部
	double image; //复数虚部
public:
	Complex(double r = 0.0, double i = 0.0){ real = r; image = i; }//构造函数
	Complex operator + (Complex c2);//运算符+重载函数
	Complex operator - (Complex c2);//运算符-重载函数
	Complex operator * (Complex c2);//运算符*重载函数
	Complex operator / (Complex c2);//运算符/重载函数
	void Show();//输出复数
};

Complex Complex::operator + (Complex c2)//重载运算符+函数实现
{
	return Complex(real + c2.real, image + c2.image);
}
Complex Complex::operator - (Complex c2)//重载运算符-函数实现
{
	return Complex(real - c2.real, image - c2.image);
}
Complex Complex::operator * (Complex c2)//重载运算符*函数实现
{
	return Complex(real*c2.real-image*c2.image, c2.real*image + real*c2.image);
}
Complex Complex::operator / (Complex c2)//重载运算符/函数实现
{
	return Complex((real*c2.real + image*c2.image)/(c2.real*c2.real+c2.image*c2.image), 
	       (c2.real*image - real*c2.image)/(c2.real*c2.real + c2.image*c2.image));
}
void Complex::Show()
{
	cout << "(" << real << "," << image << ")" << endl;
}

int main()//主函数
{
	Complex c1(5, 4);
	Complex c2(2, 10);
	Complex c3;
	cout << "c1=";
	c1.Show();
	cout << "c2=";
	c2.Show();
	c3 = c1 - c2;
	cout << "c3=c1-c2=";
	c3.Show();
	c3 = c1 + c2;
	cout << "c3=c1-c2=";
	c3.Show();
	c3 = c1 * c2;
	cout << "c3=c1*c2=";
	c3.Show();
	c3 = c1 / c2;
	cout << "c3=c1/c2=";
	c3.Show();
}

