#include <iostream>
using namespace std;


/*
// C�����еĽṹ�����ǲ��ܷź�����
// ������̣����� �� �������ݵķ������뿪��
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

// C++��Ҳ�нṹ��---��ΪC++Ҫ����C����
// C++�ṹ���п��Զ��庯��
// ��Student�ṹ��������ѧ����Ϣ
// Student����һ�������ѧ��

// ��struct����һ����--ѧ����
// ��class����һ����--ѧ����
// �ࣺ����һ�������ʵ�壬���ǶԸ�ʵ�������
// Student����һ�������ѧ�������Ƕ�Ⱥ��Ⱥ���һ������

// ��Ķ��巽ʽһ���ǽ���������붨��ȫ���������н��ж���
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
���ֶ��巽ʽ������
1. �����Ͷ���ֿ�---��Ա���������ⶨ��ʱ������Ҫ�ڳ�Ա������ǰ�ӣ�����::
2. ��������Ͷ���ȫ����������---���������ܻὫ��Ա����������������
3. һ�������-�����齫�����Ͷ���ֿ�--Ϊ�˷�ֹ�ظ�����
*/


int main()
{
	// Student���Ǿ����ѧ������ֻ�����Ƕ�ѧ����һ������
	// Student._age = 10;

	// ��Student�ṹ�嶨������Ľṹ�����͵ı���--->����Ϊһ�������ѧ��
	// ��Student��������ı���--->��Ϊֻ���󣬶��������һ��������ʵ��
	Student s1,s2,s3;
	/*
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	*/

	// InitSutdent(&s1, "Peter", "��", 30);
	// PrintStudent(&s1);
	return 0;
}
#endif


#if 0
// �����޶���
// ������󣺷�װ  �̳�  ��̬

//  ��װ�������ݺͲ������ݵķ��������л���ϣ����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿ����Ͷ�����н���
// C++�У�ͨ���ཫ���ݺͲ������ݵķ�����װ����
// ʹ�÷���Ȩ�ޣ���������Щ�����������ⲿֱ�ӱ����е���
// �����޶����޶����Ǹó�Ա�Ƿ��ܹ�������ֱ�ӱ�ʹ�ã������з���û������

class Student
{
public:// ��Ҫ�����ⱻֱ�ӵ��ã����ò��ֳ�Ա�ķ���Ȩ������Ϊpublic
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
	s1.InitStudent("Peter", "��", 30);
	s2.InitStudent("����", "Ů", 31);
	s3.InitStudent("Summer", "��", 2);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();

	// cout << s1._name << endl;
	cout << s1._age << endl;
	return 0;
}

#endif

#if 0
// һ�������һ��������
// C++������ȫ��������  �������еľֲ�������  �����ռ�  ����

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

// TestFunc�����ڲ�ͬ����������˲��Ǻ�������
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
// ��Ա����---�൱�������Ա������ȫ�ֱ���---��Ϊÿ��"��Ա����"�ж�����ֱ��ʹ��
// ע�⣺��ȫ�ֱ�����΢�е�����ȫ�ֱ�����ʹ��ǰҪ�ȶ��壬����Ա����û�д�Ҫ��Ϊʲô��
class Student
{
public:// ��Ҫ�����ⱻֱ�ӵ��ã����ò��ֳ�Ա�ķ���Ȩ������Ϊpublic
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

// ��C�����У�һ�������ڱ�ʹ��֮ǰ�����ȶ���,����ͻ����ʧ��

 int g_a = 10;

int main()
{
	cout << g_a << endl;
	return 0;
}

// int g_a = 10;---�������ʹ��֮���壬����ʧ��
#endif

#if 0
class Student
{
public:// ��Ҫ�����ⱻֱ�ӵ��ã����ò��ֳ�Ա�ķ���Ȩ������Ϊpublic
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
// ���������ֻ֪������Ҫʲô���ӵı���

�ң��ϰ�������--����                ���ʦ�����������������ͼֽ����ͼֽ---����Ա
�������������߶ȸ����ʦ�����ʦ���������������ͼֽ

���������ͼֽ(������������)-----ע�����ͼֽ������ס��----->�뽳���Ƿ�������----->�Ż��γ�һ�����������ı���(����ס�˵�)

   ��(������������)--->����ֱ��ʹ����"��Ա"-----> ʵ����---> ���������Ķ��󣨶����вſ��Է����ݣ�
*/


// ��μ���һ����Ĵ�С��
// ����Ҫ֪��һ�����а�����ʲô��

int main()
{
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