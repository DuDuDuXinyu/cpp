#if 0

#include <stdio.h>

int a = 10;

//�����ռ�Ķ���

namespace N1
{
	//���Էű���

	int a = 20;
	int b = 20;

	//���Էź���

	int Add(int left, int right)
	{
		return left + right;
	}
}

//�����ռ���Խ���Ƕ��-----���������ռ�������Զ��������ռ�

namespace N2
{
	int a = 30;
	int b = 30;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 40;
		int b = 40;

		int Mul(int left, int right)
		{
			return left * right;
		}
	}
}

//����������ͬ�������ռ�----ϵͳĬ�Ͻ���ͬ���Ƶ������ռ�ϲ�

namespace N1
{
	int c = 10;
	int d = 10;
}

int main()
{
	int a = 50;
	printf("%d\n", a);	//main�еľֲ�����a
	printf("%d\n", :: a);	//ȫ�ֱ���a�������������޶���

	printf("%d\n", N1::a);	//N1�����ռ��е�a
	printf("%d\n", N2::a);	//N2�����ռ��е�a
	printf("%d\n", N2::N3::a);	//N3�����ռ��е�a
	return 0;
}
#endif

#if 0

//c++�������ͷ�ļ�

#include <iostream>

using namespace std;//��������������ռ�

int main()
{
	int a = 0, b, c;
	scanf("%d", &a);
	cin >> b, c;
	cout << "Hello World!!!" << endl;
}
#endif


#include <iostream>

using namespace std;//��������������ռ�

#if 0
 int Add(int left, int right)
{
	return left + right;
}

 double Add(int left, int right)
{
	return left + right;
}

int main()
{
	cout << Add(10, 20) << endl;
	return 0;
}
#endif
#if 0
int main()
{
	double a = 12.34;
	const int& ra = a;
	cout << a << ra << endl;
	a = 34.56;
	cout << a << ra << endl;
	return 0;
}
#endif

#if 0
void Swap(int& a, int& b)
{
	cout << a << b << endl;
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a1 = 1, b1 = 2;
	int &a = a1,&b = b1;
	Swap(a, b);
	cout << a << b << endl;
}
#endif

#if 0
int main()
{
	int a = 0;
	int& ra = a;
	int& rb = ra;
	cout << a << endl;
	cout << ra << endl;
	cout << rb << endl;
}
#endif

#if 0
int main()
{
	const int a = 10;
	int array[a];
	return 0;
}
#endif

#if 0

#define MAX(a,b) a++;b++;cout<<a<<b<<endl;
	
	
int main()
{
	int a = 1, b = 2;
	MAX(a,b);
	return 0;
}
#endif
#if 0
int main()
{
	int a = 10;
	auto p1 = &a;
	auto* p2 = &a;
	auto ra1 = a;
	auto& ra2 = a;
	auto b = a;
	auto c = 'a';
	cout << typeid(a).name() << endl;
	cout << typeid(p1).name() << endl;
	cout << typeid(p2).name() << endl;
	cout << typeid(ra1).name() << endl;
	cout << typeid(ra2).name() << endl;
	cout << typeid(b).name() << endl;   
	cout <<typeid(c).name() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int arr[] = { 1,2,3,4,5 };
	for (auto& a : arr)
		a *= 2;
	for (auto a : arr)
		cout << a << endl;
	return 0;
}
#endif
#if 0
void f(int) { cout << "f(int)" << endl; }

void f(int*) { cout << "f(int*)" << endl; }

int main()
{
	int* p1 = nullptr;
	f(p1);
	return 0;

}
#endif

