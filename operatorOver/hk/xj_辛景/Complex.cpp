#include<iostream>
using namespace std;

class Complex
{
private:
	double real;  //����ʵ��
	double image; //�����鲿
public:
	Complex(double r = 0.0, double i = 0.0){ real = r; image = i; }//���캯��
	Complex operator + (Complex c2);//�����+���غ���
	Complex operator - (Complex c2);//�����-���غ���
	Complex operator * (Complex c2);//�����*���غ���
	Complex operator / (Complex c2);//�����/���غ���
	void Show();//�������
};

Complex Complex::operator + (Complex c2)//���������+����ʵ��
{
	return Complex(real + c2.real, image + c2.image);
}
Complex Complex::operator - (Complex c2)//���������-����ʵ��
{
	return Complex(real - c2.real, image - c2.image);
}
Complex Complex::operator * (Complex c2)//���������*����ʵ��
{
	return Complex(real*c2.real-image*c2.image, c2.real*image + real*c2.image);
}
Complex Complex::operator / (Complex c2)//���������/����ʵ��
{
	return Complex((real*c2.real + image*c2.image)/(c2.real*c2.real+c2.image*c2.image), 
	       (c2.real*image - real*c2.image)/(c2.real*c2.real + c2.image*c2.image));
}
void Complex::Show()
{
	cout << "(" << real << "," << image << ")" << endl;
}

int main()//������
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

