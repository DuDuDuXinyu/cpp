#include <iostream>

using namespace std;

#if 0
class Test
{
public:
	Test(int t)
		:_t(t)
	{
		cout << "Text():" << this << endl;
	}
	~Test()
	{
		cout << "~Text()" << this << endl;
	}
private:
	int _t;
};

//new��delete��new[]��delete[]��ʹ��

void Test1()
{
	int* p1 = new int;
	int* p2 = new int(100);
	int* p3 = new int[10];
	int* p4 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
}

//new��malloc������

void Test2()
{
	//malloc�����Ǵ�������ֻ���ڶ���������һ���Testһ����С�Ŀռ�
	//��Ϊmalloc������ù��캯��

	Test* p1 = (Test*)malloc(sizeof(Test));
	if (nullptr == p1)
	{
		return;
	}

	Test* p2 = new Test(250);	//new Test�������Ĵ�����һ�����󣬵����˹��캯��

	free(p1);	//���������������
	delete(p2);	//������������
}

int main()
{
	Test2();
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int t = 20)
		:_t(t)
		, _p(new int(10))
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _t;
	int* _p;
};

//�����Զ�������һ��Ҫƥ����һ��ʹ��

void Test1()
{
	//�����������malloc��ʱ��û�е��ù��캯��
	//delete��ʱ���������������ʱ����
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;

	//�ڴ�й¶����new��ʱ������˹��캯��
	//free��ʱ��û�е��������������������ڲ��Ŀռ�û���ͷŶ�����ڴ�й©
	Test* p2 = new Test(1);
	free (p2);


	Test* p3 = new Test[10];
	delete[] p3;
}

int main()
{
	Test1();
	
	// ����Ҫ������֮����ϸú���
	//�ڴ������н�����Ϳ�������������п��Կ����Ƿ����ڴ�й©
	_CrtDumpMemoryLeaks();  
	return 0;
}
#endif

#if 0
//�Լ�ʵ��new��delete

class Test
{
public:
	Test(int t = 20)
		:_t(t)
	{
		cout << "Text():" << this << endl;
	}
	~Test()
	{
		cout << "~Text()" << this << endl;
	}
private:
	int _t;
};

Test* New(int t)
{
	//new����������
	//1.malloc�ռ�
	//2.���ù��캯��
	Test* p = (Test*)malloc(sizeof(Test));
	new(p)Test(t);
	return p;
}

void Delete(Test* p)
{
	//delete����������
	//1.������������
	//2.�ͷſռ�
	if (nullptr == p)
		return;

	p->~Test();
	free(p);
}

Test* NewArray(int N, int t)
{
	Test* p = (Test*)malloc(sizeof(Test) * N + 4);
	*(int*)p = N;

	p = (Test*)((int*)p + 1);
	for (int i = 0; i < N; i++)
	{
		new(p + i)Test(t);
	}
	return p;
}

void DeleteArray(Test* p)
{
	if (nullptr == p)
		return;

	int* pt = (int*)p - 1;
	int N = *pt;
	for (int i = N - 1; i >= 0; i--)
	{
		p[i].~Test();
	}

	free(pt);
}

int main()
{
	Test* p1 = new Test(10);
	delete p1;

	Test* p2 = New(10);
	Delete(p2);

	Test* p3 = new Test[10];
	delete[] p3;

	Test* p4 = NewArray(10, 100);
	DeleteArray(p4);

	return 0;
}
#endif