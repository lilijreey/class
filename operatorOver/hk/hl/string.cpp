#include <iostream>
using namespace std;

class String
{
	char *str;
public:
	String(char *p = ""):str(p)
	{   }
	String(int n,char c)
	{
		int i;
		for(i=0;i<n;i++)
		{
			str[i] = c;
		}
		str[i] = '\0';
	}
	int length()const;
	String operator+(const String &a)const;
	String& operator+=(const String &a);
	friend ostream& operator<<(ostream &os,String &a);

};

int String::length()const
{
	int count = 0;
	char *p = str;
	while(*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}

String String::operator+(const String &a)const
{
	String s;
	char *p = s.str;
	char *q = str;
	char *r = a.str;
	while(*q != '\0')
	{
		*p = *q;
		p++;
		q++;
	}
	while(*r != '\0')
	{
		*p = *r;
		p++;
		r++;
	}
	*p = '\0';
	return s;
}

String& String::operator+=(const String &a)
{
	char *p = str;
	char *q = a.str;
	while(*p != '\0')
	{
		p++;
	}
	while(*q != '\0')
	{
		*p = *q;
		p++;
		q++;
	}
	*p = '\0';
	return *this;
}

ostream& operator<<(ostream &os,String &a)
{
	while(*(a.str) != '\0')
	{
		os<<*(a.str);
		a.str++;
	}
	return os;
}

int main()
{
	String a = "aaaaa";
	String b = "ss";
	a+=b;
	cout<<a<<a.length()<<endl;
}