
#if 0

不用加减乘除做加法
int Add(int num1, int num2)
{
	int n1, n2;
	n1 = (num1 & num2) << 1;
	n2 = num1 ^ num2;
	while (n1 & n2)
	{
		num1 = n1; num2 = n2;
		n1 = (num1 & num2) << 1;
		n2 = num1 ^ num2;
	}
	return n1 | n2;
}

#endif

//三角形
#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a + b > c&& a - b < c)
			if (a + c > b&& a - c < b)
				if (b + c > a&& b - c < a)
				{
					cout << "Yes" << endl;
					continue;
				}

		cout << "No" << endl;
	}
	return 0;
}