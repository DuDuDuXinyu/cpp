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


int main()
{

}