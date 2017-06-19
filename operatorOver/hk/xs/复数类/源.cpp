#include<iostream>
using namespace std;

class Complex
{
	double Real, Image;
public:
	Complex(float r = 0, float i = 0)
	{
		Real = r;
		Image = i;
	}
	void Show() const
	{
		cout << Real<< ',' << Image<< endl;
	}
	Complex &operator+(Complex &a);
	friend Complex &operator-(Complex &a);
	friend Complex operator+=(Complex &c1, Complex &c2);
	friend Complex operator-=(Complex &c1, Complex &c2);
	friend Complex operator*=(Complex &c1, Complex &c2);
	friend Complex operator/=(Complex &c1, Complex &c2);
};

Complex &operator+(Complex &a)
{
	return a;
}

Complex &operator-(Complex &a)
{
	a.Real = -a.Real;
	a.Image = -a.Image;
	return a;
}

Complex operator+=(Complex &c1,Complex &c2)
{
	c1.Real += c2.Real;
	c1.Image += c2.Image;
	return c1;
}

Complex operator-=(Complex &c1, Complex &c2)
{
	c1.Real -= c2.Real;
	c1.Image -= c2.Image;
	return c1;
}

Complex operator*=(Complex &c1, Complex &c2)
{
	Complex t;
	t.Real = c1.Real;
	c1.Real = t.Real*c2.Real - c1.Image*c2.Image;
	c1.Image = t.Real*c2.Image + c1.Image*c2.Real;
	return c1;
}

Complex operator/=(Complex &c1, Complex &c2)
{
	Complex t;
	t.Real = c1.Real;
	c1.Real = (t.Real*c2.Real + c1.Image*c2.Image)/(c2.Real*c2.Real+c2.Image*c2.Image);
	c1.Image = (c1.Image*c2.Real - t.Real*c2.Image)/(c2.Real*c2.Real + c2.Image*c2.Image);
	return c1;
}

int main()
{
	Complex a(1, 2), b(1, -2);
	//+a;
	//a.Show();
	//-a;
	//a.Show();
	//a += b;
	//a.Show();
	//a-=b;
	//a.Show();
	//a *= b;
	//a.Show();
	a /= b;
	a.Show();

	return 0;
}
