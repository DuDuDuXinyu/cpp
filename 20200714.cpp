

#if 0
变态跳台阶
int fun(int n)
{
	if (n == 1)
		return 1;
	else
		return 2 * fun(n - 1);

	//return 1<<(n-1);
}

int main()
{
	int n = 0;
	while (cin >> n)
		cout << fun(n) << endl;

	return 0;
}
#endif

//看猫能不能进入瓶子中

#include <iostream>
using namespace std;

#define π 3.14

int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n < 2.0 * r * π)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}