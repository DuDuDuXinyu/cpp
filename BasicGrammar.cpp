#if 0

#include <stdio.h>

int a = 10;

//命名空间的定义

namespace N1
{
	//可以放变量

	int a = 20;
	int b = 20;

	//可以放函数

	int Add(int left, int right)
	{
		return left + right;
	}
}

//命名空间可以进行嵌套-----就是命名空间里面可以定义命名空间

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

//可以命名相同的命名空间----系统默认将相同名称的命名空间合并

namespace N1
{
	int c = 10;
	int d = 10;
}

int main()
{
	int a = 50;
	printf("%d\n", a);	//main中的局部变量a
	printf("%d\n", :: a);	//全局变量a，：：作用于限定符

	printf("%d\n", N1::a);	//N1命名空间中的a
	printf("%d\n", N2::a);	//N2命名空间中的a
	printf("%d\n", N2::N3::a);	//N3命名空间中的a
	return 0;
}
#endif

#if 0

//c++输入输出头文件

#include <iostream>

using namespace std;//输入输出的命名空间

int main()
{
	int a = 0, b, c;
	scanf("%d", &a);
	cin >> b, c;
	cout << "Hello World!!!" << endl;
}
#endif


#include <iostream>

using namespace std;//输入输出的命名空间

extern "C" int Add(int left, int right)
{
	return left + right;
}


int main()
{
	cout << Add(10, 20) << endl;
	return 0;
}