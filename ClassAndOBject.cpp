#include <iostream>

#pragma warning (disable:4996)

using namespace std;

#if 0
//struct����������ѧ����Ϣ������ѧ��

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
	//ʹ��Student�ṹ�嶨��һ���ṹ���ѧ������

	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��", 2);

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
	//ʹ��Student�ṹ�嶨��һ���ṹ���ѧ������

	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	cout << s1._age << endl;
	return 0;
}
#endif

#if 0

//c++������ȫ�������򡢺������������������ռ䡢����

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
	//ʹ��Student�ṹ�嶨��һ���ṹ���ѧ������

	Student s1, s2, s3;
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��", 2);

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
		cout << "���������ĺ���" << endl;
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
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��",10);

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
	//ʹ��Student�ṹ�嶨��һ���ṹ���ѧ������

	Student s1;
	s1.InitStudent("Peter", "��", 30);

	Student* ps = &s1;
	ps->PrintStudent();


	ps = nullptr;

	//Ϊ��ֱ�Ӿ��޷����ʣ�Ȼ��ͻᱨ��

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
	//��һ���ȶ������һ�����һ��ִ����������
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
		cout << "string��������" << endl;
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
	//��text�д�����String s������text�����˳�ʱ�������������ͷ�s�Ŀռ�
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
		cout << "string��������" << endl;
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
	//ǰ��++
	Time& operator++()
	{
		_day += 1;
		return *this;
	}
	//����++
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
		cout << "string��������" << endl;
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
		cout << "�������캯��" << endl;
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

	//��days��֮������һ��

	Time operator+(int days)
	{
		Time temp(*this);
		temp._day += days;
		return temp;
	}

	//��days��֮������һ��

	Time& operator+=(int days)
	{
		_day += days;
		return *this;
	}

	//��daysǰ֮������һ��

	Time operator-(int days)
	{
		Time temp(*this);
		temp._day += days;
		return temp;
	}
	//��daysǰ֮������һ��

	Time operator-=(int days);
	//��daysǰ֮������һ��

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

	//printTime��һ����ͨ�ĳ�Ա�������ú��������޸ĳ�Ա
	//����t2��const���ε����Բ��ܵ��÷�const���εĺ���
	
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

//count�ڸ��ԵĶ������ǵ������ڣ�����ı�һ�����ñ�ĸı�

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
		cout << "���캯��" << endl;
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

//��̬������������ĳ�Ա���������Բ�ռ����Ŀռ�
class Time
{
public:
	Time(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		count++;
		cout << "���캯��" << endl;
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
		cout << "���캯��" << endl;
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

	//��̬��Ա����û��thisָ��
	//���Ծ�̬��Ա����������const������
	//��Ϊ��const���γ�Ա�����ı������޸�thisָ��
	//�޷����ʷǾ�̬�ĳ�Ա

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

	//�ᱨ������Ϊcount��˽�еģ�����������ʹ��
	//cout << Time::count << endl;
	cout << t1.GetCount() << endl;
	
	return 0;
}
#endif

//��Ԫ��
class Time
{
	//Data��Time����Ԫ��
	//Data���Է���Time�ĳ�Ա
	//Time�����Է���Data�ĳ�Ա
	friend class Data;
private:
	int hour = 10;
	int minute = 05;
	int second = 59;
};

class Data
{
	//��Ԫ���������Է��ʸ����еĳ�Ա������private��protected��Ҳ���Է���
	friend ostream& operator << (ostream& _cout, const Data& d);
public:
	Data(int year = 1970, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "���캯��" << endl;
	}
	Data(Data& t)
		:_year(t._year)
		, _month(t._month)
		, _day(t._day)
	{
		cout << "�������캯��" << endl;
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
//��һ������������oatream&
//Ҫ�з���ֵ������ostream&--->ԭ����Ϊ��֧��������ӡ
//��������ֻ�ܰ��������Ϊȫ�ֺ���
ostream& operator << (ostream& _cout,const Data& d)
{
	_cout << d._year << "/" << d._month << "/" << d._day;
	return _cout;
}
int main()
{
	Data d1(2020, 4, 27);

	//���ֵ��ò�����������������д����
	//<<�涨����һ������������ostream���������
	//��Ӧ���е����غ���
	//t1 << cout;

	cout << d1<<endl;
	d1.printTime();
	
	return 0;
}