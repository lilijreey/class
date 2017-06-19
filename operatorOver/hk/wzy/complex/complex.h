class Complex//复数类
{
private:
	double _real;//实部
	double _image;//虚部
public:
	//构造函数
	Complex(double real = 0,double image = 0);
	
	//双目运算符+号重载
	const Complex operator+(const Complex& right);
	
	//双目运算符-号重载
	const Complex operator-(const Complex& right);
	
	//双目运算符*号重载
	const Complex operator*(const Complex& right);
	
	//双目运算符/号重载
	const Complex operator/(const Complex& right);
	
	//复数的长度，即模长
	double GetLenth() const;
	//求一个复数对象的共轭
	const Complex Conjugate() const;
	
	//输出 << 的重载，声明为Comolex类的友元函数
	friend std::ostream & operator<<(std::ostream &os,const Complex& c);
	
	//打印一个复数对象，以 a+bi 的形式
	void Show() const;				
};