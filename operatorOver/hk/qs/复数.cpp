
#include<iostream>

using std::cout;
using std::endl;
using std::ostream;

class complex
{
private:
	double a;
	double b;
public:
	complex();
	complex(int x,int y);
	complex operator+(const complex &j) const;
	complex operator-(const complex &j) const;
	complex operator+=(const complex &j);
	complex operator-=(const complex &j);
	complex operator*(const complex &j) const;
	complex operator/(const complex &j) const;

	friend ostream & operator<<(ostream &p,complex &pp);
};

complex::complex()
{
	a=b=0;
}

complex::complex(int x,int y)
{
	a=x;
	b=y;
}

complex complex::operator+(const complex &j)const
{

	complex sum;
	sum.a = a + j.a;
	sum.b = b +j.b;
	return sum;
}

complex complex::operator-(const complex &j)const
{
	complex ch;
	ch.a=a-j.a;
	ch.b=b-j.b;
	return ch;
}

complex complex::operator+=(const complex &j)
{
	a+=j.a;
	b+=j.b;
	return *this;
}

complex complex::operator-=(const complex &j)
{
	a-=j.a;
	b-=j.b;
	return *this;
}

complex complex::operator*(const complex &j)const
{
	complex ch;
	ch.a=a*j.a;
	ch.b=b*j.b;
	return ch;
}

complex complex::operator/(const complex &j)const
{
	complex ch;
	ch.a=a/j.a;
	ch.b=b/j.b;
	return ch;

}

ostream & operator<<(ostream &p,complex &pp)
{
	p<<pp.a<<"+"<<"("<<pp.b<<"i"<<")"<<endl;
	return p;
}

int main()
{
	complex qs(1,-2);
	complex sq(2,3);
	complex a=qs+sq;
	complex b=qs-sq;
	complex c=(qs+=sq);
	complex d=(qs-=sq);
	complex e=qs*sq;
	complex f=qs/sq;
  int a=3;
  int b=5;
  b+=a += 4;
	cout<<qs<<endl;
	cout<<sq<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	cout<<e<<endl;
	cout<<f<<endl;

}
