#include <iostream>
#include <cstdio>
using namespace std;

class Complex
{
private:
	double a;//Êµ²¿
	double b;//Ðé²¿
public:
	Complex(double a = 0,double b = 0) : a(a),b(b)	{

	}

	Complex operator+(const Complex tmp){
		Complex retval;
		retval.a = this->a + tmp.a;
		retval.b = this->b + tmp.b;
		
		return retval;
	}
	Complex operator-(const Complex tmp)	{
		Complex retval;
		retval.a = this->a - tmp.a;
		retval.b = this->b - tmp.b;
		
		return retval;
	}
	Complex operator*(const Complex tmp){
		Complex retval;
		retval.a = this->a * tmp.a - this->b*tmp.b;
		retval.b = this->b *tmp.a + this->a*tmp.b;
		
		return retval;
	}

	Complex operator/(const Complex tmp){
		Complex retval;
		retval.a = (this->a * tmp.a + this->b * tmp.b) / (tmp.a * tmp.a + tmp.b * tmp.b);
		retval.b = (this->b * tmp.a+ this->a * tmp.b) / (tmp.a * tmp.a + tmp.b * tmp.b);
		
		return retval;
	}
	friend	ostream& operator<<(ostream &os,Complex a);
};

	ostream& operator<<(ostream &os,Complex n){
		if(n.b < 0)
		{
			os<<n.a<<n.b<<"i";
		}
		else if(n.b == 0)
		{
			os<<n.a;
		}
		else
		{
			os<<n.a<<"+"<<n.b<<"i";
		}

		return os;
	}

int main(){
	Complex a(1.2,-2);
	Complex b(3,4);
	Complex c(1,0);
	Complex z = a+b;
	Complex y = a/b;

	cout<< c <<","<<a<<","<<b<<endl;
	cout<<y<<endl;

	return 0;
}
