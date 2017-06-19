#include<iostream>
#include<assert.h>

using namespace std;

class complex 
{
	double real,
         image;
public:
	complex(double rr=0, double ii=0)
	{
    real  = rr;
    image = ii;
  }

	complex(const complex &c)
	{ 
    real=c.real; 
    image=c.image;  
  }

  double getReal() const {
    return real;
  }


  bool is_right(double r, double i) {
    return r == real && image == i;

  }

  friend ostream &operator <<(std::ostream &output, 
                              const complex &c) ;

  complex complex::operator =(const complex &c);
  complex complex::operator +(const complex &c);
  complex complex::operator -(const complex &c);
  complex complex::operator *(const complex &c);
  complex complex::operator /(const complex &c);
};

complex complex::operator +(const complex &c)
{
  return complex(real+c.real,image+c.image);
}

complex complex::operator -(const complex &c)
{
  return complex(real-c.real,image-c.image);
}

complex complex::operator *(const complex &c)
{
  return complex(real*c.real - image*c.image,
                 real*c.image + image*c.real);
}

complex complex::operator /(const complex &c)
{
  double a,b,t;
  a=c.real*c.real + c.image*c.image;
  b=(real*c.real + image*c.image)/a;
  t=(image*c.real - real*c.image)/a;
  return complex(b,t);
}

ostream &operator <<(std::ostream &output, const complex &c) 
{ 
    output << c.real; 
    if (c.image > 0)
    { 
        output << "+" << c.image<<"i"; 
        return output; 
    } 
    if (c.image < 0) 
    { 
        output << c.image<<"i"; 
        return output; 
    } 
    return output; 
} 
 
int main()
{	
  complex a;
  //assert(a.real == 0);
  //assert(a.== 0);
  complex c1,
          c2(6,3),
          c3(4);

  c1 = c2 - c3;
  c1 = c2 * c3;

  assert(c1.is_right(3,4));

  
  cout<<c1;
}
