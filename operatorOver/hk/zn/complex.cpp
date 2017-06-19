#include <iostream>
using std::endl;
using std::cout;
using std::ostream;

class complex
{
private:
	double a; 
	double b;
public:
	complex(int a = 0, int b = 0) :a(a), b(b)
	{}
	~complex()
	{}

	const complex operator+(const complex& rvalue)const
	{
		cout << "me!+" << endl;
		complex tmp;
		tmp.a = this->a + rvalue.a;
		tmp.b = this->b + rvalue.b;
		return tmp;
	}

	const complex operator-(const complex& rvalue)const
	{
		cout << "me!-" << endl;
		complex tmp;
		tmp.a = this->a - rvalue.a;
		tmp.b = this->b - rvalue.b;
		return tmp;
	}

	const complex operator*(const complex& rvalue)const
	{
		cout << "me!*" << endl;
		complex tmp;
		if (rvalue.a != 0 && rvalue.b != 0)
		{
			tmp.a = this->a * rvalue.a - this->b * rvalue.b;
			tmp.b = this->a * rvalue.b + this->b * rvalue.a;
		}
		return tmp;
	}

	const complex operator/(const complex& rvalue)const
	{
		cout << "me!/" << endl;
		complex tmp;
		tmp.a = this->a * rvalue.a / (rvalue.a*rvalue.a + rvalue.b*rvalue.b) - this->b * rvalue.b / (rvalue.a*rvalue.a + rvalue.b*rvalue.b);
		tmp.b = this->a * rvalue.b / (rvalue.a*rvalue.a + rvalue.b*rvalue.b) + this->b * rvalue.a / (rvalue.a*rvalue.a + rvalue.b*rvalue.b);
		return tmp;
	}

	const complex& operator=(const complex& a)
	{
		cout << "me!=" << endl;
		this->a = a.a;
		this->b = a.b;
		return *this;
	}

	friend ostream & operator<<(ostream &os, complex &other);

	/*void show()const
	{
	if (this->a == 0 && this->b == 0)
	{
	cout << 0;
	}
	else
	if (this->b < 0)
	{
	cout << this->b << std::endl;
	}
	else if (this->b == 0)
	{
	cout << endl;
	}
	else
	{
	cout << "+" << this->b << endl;
	}
	}*/
};


ostream & operator<<(ostream &os, complex &value)
{
	if (value.a == 0)
	{
		if (value.b == 0)
		{
			os << 0;
		}
		else
		{
			os << value.b << "i";
		}
    return os;
	}

  if (value.b == 0)
  {
    os << value.a;
    return os;
  }

  if (value.b > 0)
  {
    os << value.a << "+" << value.b << "i";
    return os;
  }

  os << value.a << value.b << "i";
  return os;
}

//#include"complex.h"

int main()
{

	complex a(1, 2);
	complex b;
	b = a;
	complex c = a + b;
	complex d = a / b;
	complex e = a * b;
	complex f = a - b;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

	return 0;
}
