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