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

extern "C" int Add(int left, int right)
{
	return left + right;
}


int main()
{
	cout << Add(10, 20) << endl;
	return 0;
}