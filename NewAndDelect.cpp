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

//new和delete、new[]和delete[]的使用

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

//new和malloc的区别

void Test2()
{
	//malloc并不是创建对象，只是在堆上申请了一块和Test一样大小的空间
	//因为malloc不会调用构造函数

	Test* p1 = (Test*)malloc(sizeof(Test));
	if (nullptr == p1)
	{
		return;
	}

	Test* p2 = new Test(250);	//new Test是真正的创建了一个对象，调用了构造函数

	free(p1);	//不会调用析构函数
	delete(p2);	//调用析构函数
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

//对于自定义类型一定要匹配在一起使用

void Test1()
{
	//代码崩溃，在malloc的时候并没有调用构造函数
	//delete的时候调用析构函数的时候奔溃
	Test* p1 = (Test*)malloc(sizeof(Test));
	delete p1;

	//内存泄露，在new的时候调用了构造函数
	//free的时候没有调用析构函数，导致类内部的空间没有释放而造成内存泄漏
	Test* p2 = new Test(1);
	free (p2);


	Test* p3 = new Test[10];
	delete[] p3;
}

int main()
{
	Test1();
	
	// 在需要检测代码之后加上该函数
	//在代码运行结束后就可以在输出窗口中可以看到是否有内存泄漏
	_CrtDumpMemoryLeaks();  
	return 0;
}
#endif

#if 0
//自己实现new与delete

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
	//new有俩个功能
	//1.malloc空间
	//2.调用构造函数
	Test* p = (Test*)malloc(sizeof(Test));
	new(p)Test(t);
	return p;
}

void Delete(Test* p)
{
	//delete的俩个功能
	//1.调用析构函数
	//2.释放空间
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