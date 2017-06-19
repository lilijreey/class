#include <cstring>
#include <cassert>
#include <iostream>

const int INITSIZE = 10;

class String
{
private:
	char * _str;
	int _size;
	int _usedsize;
public:
	String() :
		_str(nullptr), _size(0), _usedsize(0)
	{}

	String(const char *str);
	String(const String& other);

	const String& operator=(const char *str);
	const String& operator=(const String& other);

	const String operator+(const char *str) const ;
	const String operator+(const String& right);

	void Show() const;

	~String();

	friend std::ostream& operator<<(std::ostream& os ,const String& s);
};

String::String(const char *str)
{
	_size = INITSIZE;
	int size = strlen(str);
	while (size > _size)
	{
		_size *= 2;
	}

	_str = new char[_size];
	assert(nullptr != _str);
	for (int i = 0;i < size;i++)
	{
		_str[i] = str[i];
	}
	_usedsize = size;
}

String::String(const String& other)
{
	_size = other._size;
	_usedsize = other._usedsize;
	_str = new char[_size];
	for (int i = 0;i < _usedsize;i++)
	{
		_str[i] = other._str[i];
	}
}

const String& String::operator=(const char *str)
{
	assert(str != nullptr);
	int len = strlen(str);

	if (this->_str != nullptr)
	{
		delete[](this->_str);
		if (this->_size < len)
		{
			this->_str = new char[len];
			this->_size = len;
		}
	}
	else
	{
		this->_str = new char[len];
		this->_size = len;
	}
	for (int i = 0;i < _size;i++)
	{
		_str[i] = str[i];
	}
	this->_usedsize = len;

	return *this;
}
const String& String::operator=(const String& other)
{
	if (&other == this)
	{
		return *this;
	}

	if (this->_str != nullptr)
	{
		delete[](this->_str);
		this->_str = new char[other._size];
	}
	else
	{
		this->_str = new char[other._size];
	}
	this->_size = other._size;

	for (int i = 0;i < other._usedsize;i++)
	{
		this->_str[i] = other._str[i];
	}
	this->_usedsize = other._usedsize;

	return *this;
}

const String String::operator+(const char *str)
{
	assert(str != nullptr);
	int len = strlen(str);

	String tmp;
	tmp._size = _usedsize + len;
	tmp._str = new char[tmp._size];
	assert(nullptr != tmp._str);
	int i = 0;
	int j = 0;
	for (i = 0;i < this->_usedsize;i++)
	{
		tmp._str[i] = this->_str[i];
	}
	for (j = 0;j < len;j++)
	{
		tmp._str[j + i] = str[j];
	}
	tmp._usedsize = this->_usedsize + len;

	return tmp;
}

const String String::operator+(const String& right)
{
	String tmp;
	tmp._size = this->_usedsize + right._usedsize;
	tmp._str = new char[tmp._size];
	assert(nullptr != tmp._str);
	int i = 0;
	int j = 0;
	for (i = 0;i < this->_usedsize;i++)
	{
		tmp._str[i] = this->_str[i];
	}
	for (j = 0;j < right._usedsize;j++)
	{
		tmp._str[j + i] = right._str[j];
	}
	tmp._usedsize = this->_usedsize + right._usedsize;

	return tmp;
}

void String::Show() const
{
	for (int i = 0;i < this->_usedsize;i++)
	{
		std::cout << this->_str[i];
	}
	std::cout << std::endl;
}

String::~String()
{
	_size = 0;
	delete[](_str);
	_str = nullptr;
	_usedsize = 0;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	for (int i = 0;i < s._usedsize;i++)
	{
		os << s._str[i];
	}

	return os;
}

int main()
{
	String s1 = "hello world . ";
	s1.Show();
	String s2;
	s2 = "i am amao . ";
	s2.Show();
	String s3;
	s3 = s1 + s2;
	s3.Show();
	String s4;
	s4 = s1 + "i am xiaohua . ";
	s4.Show();

	String s5("abcdefg");
	s5.Show();
	String s6(s1);
	s6.Show();

	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "s3 = " << s3 << std::endl;
	std::cout << "s4 = " << s4 << std::endl;
	std::cout << "s5 = " << s5 << std::endl;
	std::cout << "s6 = " << s6 << std::endl;
  int i=4;
  i=i;

	return 0;
}
