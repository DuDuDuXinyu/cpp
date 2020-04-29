#include <iostream>

#pragma warning (disable:4996)

using namespace std;

#if 0
//struct是用来描述学生信息并不是学生

struct Student
{
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	//使用Student结构体定出一个结构体的学生变量

	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif


#if 0
struct Student
{
public:
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;
};

int main()
{
	//使用Student结构体定出一个结构体的学生变量

	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << s1._age << endl;
	return 0;
}
#endif

#if 0

//c++作用域：全局作用域、函数体中作用域、命名空间、类域

void TextFun()
{}

void fun()
{
	void TextFun()
	{}
}

namespace N
{
	void TextFun()
	{}
}

class Text
{
	void TextFun()
	{}
};

int main()
{
	TestFunc();
	N::TestFunc();

	Test t;
	t.TestFunc();
	return 0;
}
#endif

#if 0

class Student
{
public:
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;
};

int main()
{
	//使用Student结构体定出一个结构体的学生变量

	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << sizeof(Student) << endl;

	return 0;
}
#endif

#if 0
class A
{
public:
	void fun();

	int a;
};

class B
{
	void fun();
};

class C
{

};

int main()
{
	cout << sizeof(A) << endl;		//4
	cout << sizeof(C) << endl;		//1
	cout << sizeof(C) << endl;		//1
}
#endif

#if 0
class Student
{
public:
	void InitStudent(const char* name, const char* gender, int age)
	{
		cout << _age << endl;
		strcpy(this->_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
		
	}

	void text(...)
	{
		cout << "不定参数的函数" << endl;
	}
private:
	char _name[20];
	char _gender[3];
protected:
	int _age=100;
};

int main()
{

	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公",10);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	s1.text(10);
	s1.text();
	s1.text(10,100);
	s1.text(10,102,16);
	return 0;
}
#endif

#if 0

class Student
{
public:
	void InitStudent(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << this << endl;
		cout << _name << "-" << _gender << "-" << _age << endl;
	}
private:
	char _name[20];
	char _gender[3];
protected:
	int _age;
};

int main()
{
	//使用Student结构体定出一个结构体的学生变量

	Student s1;
	s1.InitStudent("Peter", "男", 30);

	Student* ps = &s1;
	ps->PrintStudent();


	ps = nullptr;

	//为空直接就无法访问，然后就会报错

	ps->PrintStudent();

	return 0;
}
#endif 

#if 0
class Time
{
public:
	Time()
	{

	}
	~Time()
	{
		cout << _year<<"xigouhanshu " << endl;
	}
	Time(int year)
	{
		_year = year;
	}
	Time(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void setTime(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year=1999;
	int _month=1;
	int _day=1;
};

int main()
{
	//哪一个先定义的哪一个最后一个执行析构函数
	Time s;
	Time t(2000);
	
	s.setTime(2020, 4, 5);
	t.printTime();
	s.printTime();
	return 0;
}
#endif
#if 0 

class String
{
public:
	String(const char* str = nullptr)
	{
		_str = (char*)malloc(sizeof(char) * (1+strlen(str)));
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
		cout << "string析构函数" << endl;
	}
private:
	char* _str;
};
void text()
{
	String s("hello");
}
int main()
{
	//在text中创建的String s，会在text函数退出时调用析构函数释放s的空间
	text();
	String s("hello123");
	cout << 16513 << endl;
	return 0;
}
#endif

#if 0
class Time
{
public:
	~Time()
	{
		cout << _year << "xigou " << endl;
	}
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void setTime(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Time d1(2020,4,6);
	Time d3(1020, 4, 6);
	Time d2(d1);
	d2.printTime();
	d1.printTime();

	return 0;
}
#endif

#if 0
class String
{
public:
	String(const char* str = nullptr)
	{
		_str = (char*)malloc(sizeof(char) * (1 + strlen(str)));
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
		cout << "string析构函数" << endl;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);

	return 0;
}
#endif
#if 0
enum Data
{
	ONE, TWO, THREE
};
int operator+(int left, Data right)
{
	return left + right;
}

int main()
{

}
#endif

#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void setTime(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	//前置++
	Time& operator++()
	{
		_day += 1;
		return *this;
	}
	//后置++
	Time operator++(int)
	{
		Time temp(*this);
		_day += 1;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Time d(2020, 4, 26);
	Time r;
	r = d++;
	d.printTime();
	r.printTime();
	r = ++d;
	d.printTime();
	r.printTime();

	return 0;
}
#endif
#if 0

class String
{
public:
	String(const char* str = nullptr)
	{
		_str = (char*)malloc(sizeof(char) * (1 + strlen(str)));
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
		cout << "string析构函数" << endl;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2("world");

	s2 = s1;

	return 0;
}
#endif 

#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	Time operator = (const Time& t)
	{
		if (this != &t)
		{
			_year = t._year;
			_month = t._month;
			_day = t._day;
		}
		return t;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Time d(2020, 4, 26);
	Time r;
	r.printTime();
	r = d;
	
	r.printTime();
	return 0;

}
#endif 
#if 0

int main()
{
	int a = 10, b = 20, c = 30;
	a = b = c;
	cout << a << b << c << endl;
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "拷贝构造函数" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	Time operator = (const Time& t)
	{
		if (this != &t)
		{
			_year = t._year;
			_month = t._month;
			_day = t._day;
		}
		return *this;
	}

	//第days天之后是哪一天

	Time operator+(int days)
	{
		Time temp(*this);
		temp._day += days;
		return temp;
	}

	//第days天之后是哪一天

	Time& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	//第days前之后是哪一天

	Time operator-(int days)
	{
		Time temp(*this);
		temp._day += days;
		return temp;
	}
	//第days前之后是哪一天

	Time operator-=(int days);
	//第days前之后是哪一天

	Time operator-(const Time& t);
private:
	int _year;
	int _month;
	int _day;
};
#endif

#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	void fun()const
	{
		//_year = 1;
		_day = 1;
	}
private:
	int _year;
	int _month;
	mutable int _day;
};
int main()
{
	Time t(2020, 4, 27);
	t.printTime();
	t.fun();
	t.printTime();
	return 0;
}
#endif
#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	void fun()const
	{
		//_year = 1;
		_day = 1;
	}
private:
	int _year;
	int _month;
	mutable int _day;
};

int main()
{
	Time t1(2020, 4, 27);
	const Time t2(2020, 4, 27);

	//printTime是一个普通的成员函数，该函数可以修改成员
	//但是t2是const修饰的所以不能调用非const修饰的函数
	
	//t2.printTime();
	return 0;

}
#endif

#if 0
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
	}
	Time(const Time& t)
	{
		_year = t._year;
		_month = t._month;
		_day = t._day;
		cout << "asfgasg" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Time t1(2020, 4, 27);
	t1.printTime();
	
	return 0;
}
#endif

#if 0

//count在各自的对象中是单独存在，不会改变一个而让别的改变

class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
		,count(0)
	{
		count++;
		cout << "构造函数" << endl;
	}
	Time(Time& t)
		:_year(t._year)
		, _month(t._month)
		, _day(t._day)
		, count(++t.count)
	{
		cout << "asfgasg" << endl;
	}
	~Time()
	{
		count--;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	int count;
};
int main()
{
	Time t1(2020, 4, 27);
	Time t2(t1);

	return 0;
}
#endif 

#if 0

//静态变量不属于类的成员变量，所以不占用类的空间
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		count++;
		cout << "构造函数" << endl;
	}
	Time(Time& t)
		:_year(t._year)
		, _month(t._month)
		, _day(t._day)
	{
		count++;
		cout << "asfgasg" << endl;
	}
	~Time()
	{
		count--;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	static int count;
};
int Time::count = 0;
int main()
{
	Time t1(2020, 4, 27);
	Time t2(t1);

	cout << sizeof(Time) << endl;

	return 0;
}
#endif

#if 0

class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		count++;
		cout << "构造函数" << endl;
	}
	Time(Time& t)
		:_year(t._year)
		, _month(t._month)
		, _day(t._day)
	{
		count++;
		cout << "asfgasg" << endl;
	}
	~Time()
	{
		count--;
	}

	//静态成员函数没有this指针
	//所以静态成员函数不能用const来修饰
	//因为，const修饰成员函数的本质是修改this指针
	//无法访问非静态的成员

	static int GetCount()
	{
		//cout << this << endl;
		//cout << _year << endl;

		return count;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	static int count;
};
int Time::count = 0;
int main()
{
	Time t1(2020, 4, 27);
	Time t2(t1);

	//会报错，因为count是私有的，不能在类外使用
	//cout << Time::count << endl;
	cout << t1.GetCount() << endl;
	
	return 0;
}
#endif

//友元类
class Time
{
	//Data是Time的友元类
	//Data可以访问Time的成员
	//Time不可以访问Data的成员
	friend class Data;
private:
	int hour = 10;
	int minute = 05;
	int second = 59;
};

class Data
{
	//友元函数，可以访问该类中的成员变量，private和protected的也可以访问
	friend ostream& operator << (ostream& _cout, const Data& d);
public:
	Data(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "构造函数" << endl;
	}
	Data(Data& t)
		:_year(t._year)
		, _month(t._month)
		, _day(t._day)
	{
		cout << "拷贝构造函数" << endl;
	}
	void printTime()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
		cout << _t.hour << "/" << _t.minute << "/" << _t.second<< endl;
	}


	/*void operator << (ostream& _cout)
	{
		_cout << _year << "/" << _month << "/" << _day << endl;
	}*/
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
//第一个参数必须是oatream&
//要有返回值，返回ostream&--->原因是为了支持连续打印
//所以我们只能把这个重载为全局函数
ostream& operator << (ostream& _cout,const Data& d)
{
	_cout << d._year << "/" << d._month << "/" << d._day;
	return _cout;
}
int main()
{
	Data d1(2020, 4, 27);

	//这种调用不符合我们正常的书写规则
	//<<规定：第一个参数必须是ostream对象的引用
	//对应类中的重载函数
	//t1 << cout;

	cout << d1<<endl;
	d1.printTime();
	
	return 0;
}