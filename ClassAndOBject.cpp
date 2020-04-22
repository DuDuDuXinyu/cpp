#include <iostream>
using namespace std;


/*
// C语言中的结构体中是不能放函数的
// 面向过程：数据 和 操作数据的方法分离开的
struct Student
{
	void InitStudent(struct Student* ps, char* name, char* gender, int age)
	{}

	char* name;
	char* gender;
	int age;
};
*/

#if 0

// C++中也有结构体---因为C++要兼容C语言
// C++结构体中可以定义函数
// 用Student结构体来描述学生信息
// Student不是一个具体的学生

// 用struct定义一个类--学生类
// 用class定义一个类--学生类
// 类：不是一个具体的实体，它是对该实体的描述
// Student不是一个具体的学生，它是对群生群体的一种描述

// 类的定义方式一：是将类的声明与定义全部放在类中进行定义
class Student
{
	void InitStudent(char* name, char* gender, int age)
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


/*
两种定义方式的区别：
1. 声明和定义分开---成员函数在类外定义时，必须要在成员函数名前加：类名::
2. 如果声明和定义全部放在类中---编译器可能会将成员函数当成内联函数
3. 一般情况下-都建议将声明和定义分开--为了防止重复包含
*/


int main()
{
	// Student不是具体的学生，它只不过是对学生的一种描述
	// Student._age = 10;

	// 用Student结构体定义出来的结构体类型的变量--->称作为一个具体的学生
	// 用Student定义出来的变量--->称为只对象，对象才算是一个真正的实体
	Student s1,s2,s3;
	/*
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	*/

	// InitSutdent(&s1, "Peter", "男", 30);
	// PrintStudent(&s1);
	return 0;
}
#endif


#if 0
// 访问限定符
// 面向对象：封装  继承  多态

//  封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行交互
// C++中：通过类将数据和操作数据的方法包装起来
// 使用访问权限：来控制那些方法可以再外部直接被进行调用
// 访问限定符限定的是该成员是否能够在类外直接被使用，对类中访问没有限制

class Student
{
public:// 想要在类外被直接调用，将该部分成员的访问权限设置为public
	void InitStudent(char* name, char* gender, int age)
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
	Student s1, s2, s3;
	s1.InitStudent("Peter", "男", 30);
	s2.InitStudent("静静", "女", 31);
	s3.InitStudent("Summer", "公", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	// cout << s1._name << endl;
	cout << s1._age << endl;
	return 0;
}

#endif

#if 0
// 一个类就是一个作用域
// C++作用域：全局作用域  函数体中的局部作用域  命名空间  类域

void TestFunc()
{}

namespace N
{
	void TestFunc(int)
	{}
}

class Test
{
public:
	void TestFunc(double)
	{}

};

// TestFunc隶属于不同的作用域，因此不是函数重载
int main()
{
	TestFunc();
	N::TestFunc(10);

	Test t;
	t.TestFunc(12.34);
	return 0;
}
#endif

#if 0
// 成员变量---相当于是类成员函数的全局变量---因为每个"成员函数"中都可以直接使用
// 注意：和全局变量稍微有点区别，全局变量在使用前要先定义，而成员变量没有此要求，为什么？
class Student
{
public:// 想要在类外被直接调用，将该部分成员的访问权限设置为public
	void InitStudent(char* name, char* gender, int age)
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

// 在C语言中：一个变量在被使用之前必须先定义,否则就会编译失败

 int g_a = 10;

int main()
{
	cout << g_a << endl;
	return 0;
}

// int g_a = 10;---如果放在使用之后定义，编译失败
#endif

#if 0
class Student
{
public:// 想要在类外被直接调用，将该部分成员的访问权限设置为public
	void InitStudent(char* name, char* gender, int age)
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

/*
// 建造别墅：只知道我想要什么样子的别墅

我：老板提需求--别墅                设计师：根据描述画出设计图纸画出图纸---程序员
将别墅的描述高度给设计师，设计师根据描述画出设计图纸

别墅的设计图纸(用来描述别墅)-----注意设计图纸还不能住人----->请匠人是否来建造----->才会形成一栋真真正正的别墅(可以住人的)

   类(用来描述对象)--->不能直接使用其"成员"-----> 实例化---> 真真正正的对象（对象中才可以放数据）
*/


// 如何计算一个类的大小？
// 必须要知道一个类中包含有什么？

int main()
{
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


class A
{
public:
	void funa()
	{}

	int a;
};

class B
{
public:
	void funb()
	{}
};

class C
{};


int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;

	return 0;
}