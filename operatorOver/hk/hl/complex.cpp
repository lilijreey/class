#include <iostream>
using namespace std;

class complex
{
	double real;
	double imag;
public:
	complex(double x=1,double y=1):real(x),imag(y)
	{    }
	complex operator+(const complex &a)const;
	complex operator-(const complex &a)const;
	complex operator*(const complex &a)const;
	complex operator/(const complex &a)const;
	bool operator==(const complex &a)const;
	complex& operator+=(const complex &a);
	complex& operator-=(const complex &a);
	complex& operator*=(const complex &a);
	complex& operator/=(const complex &a);
	friend ostream& operator<<(ostream &os,complex &a);
};

complex complex::operator+(const complex &a)const
{
	complex m;
	m.real = real + a.real;
	m.imag = imag + a.imag;
	return m;
}

complex complex::operator-(const complex &a)const
{
	complex m;
	m.real = real - a.real;
	m.imag = imag - a.imag;
	return m;
}

complex complex::operator*(const complex &a)const
{
	complex m;
	m.real = real*a.real - imag*a.imag;
	m.imag = real*a.imag + imag*a.real;
	return m;
}

complex complex::operator/(const complex &a)const
{
	complex m;
	m.real = (real*a.real + imag*a.imag)/(a.real*a.real + a.imag*a.imag);
	m.imag = (imag*a.real - real*a.imag)/(a.real*a.real + a.imag*a.imag);
	return m;
}

bool complex::operator==(const complex &a)const
{
	return (real==a.real && imag==a.imag);
}

complex& complex::operator+=(const complex &a)
{
	imag += a.imag;
	real += a.real;
	return *this;
}
	
complex& complex::operator-=(const complex &a)
{
	real -= a.real;
	imag -= a.imag;
	return *this;
}

complex& complex::operator*=(const complex &a)
{
	double t=real;
	real = real*a.real - imag*a.imag;
	imag = t*a.imag + imag*a.real;
	return *this;
}

complex& complex::operator/=(const complex &a)
{
	double t=real;
	real = (real*a.real + imag*a.imag)/(a.real*a.real + a.imag*a.imag);
	imag = (imag*a.real - t*a.imag)/(a.real*a.real + a.imag*a.imag);
	return *this;
}

ostream& operator<<(ostream &os,complex &a)
{
	if(a.real==0&&a.imag==0)
	{
		os<<"0";
	}
	else if(a.real!=0&&a.imag==0)
	{
		os<<a.real;
	}
	else if(a.real==0&&a.imag!=0)
	{
		os<<a.imag<<"i";
	}
	else
	{
		if(a.imag>0)
		{
			os<<a.real<<"+"<<a.imag<<"i";
		}
		else
		{
			os<<a.real<<a.imag<<"i";
		}
	}
	return os;
}

int main()
{
	complex a(1,1);
	complex b(1,5);
	complex c(2,2);
	complex d(1,4);
	complex e(4,2);
	complex f(2,2);
	cout<<"a="<<a<<"  b="<<b<<"  c="<<c<<"  d="<<d<<"  e="<<e<<"  f="<<f<<endl;
	cout<<"a+b="<<a+b<<"\na-b="<<a-b<<"\na*b="<<a*b<<"\na/b="<<a/b<<endl;
	if(c==f)
	{
		cout<<"c==f"<<endl;
	}
	b+=a;
	cout<<"b+=a  b="<<b<<endl;
	c-=a;
	cout<<"c-=a  c="<<c<<endl;
	d*=a;
	cout<<"d*=a  d="<<d<<endl;
	e/=a;
	cout<<"e/=a  e="<<e<<endl;
}
