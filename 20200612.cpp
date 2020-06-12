#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	void foo()
	{
		cout << "1";
	}
	virtual void fun()
	{
		cout << "2";
	}
};

class B: public A
{
public:
	void foo()
	{
		cout << "3";
	}
	virtual void fun()
	{
		cout << "4";
	}
};

int getLCA(int a, int b) {
	while ((a / 2) == (b / 2))
		a /= 2, b /= 2;
	return a / 2;
}

void easy(int num)
{
	int k = 0;
	for (; num != 0; k++)
		num = num & (num << 1);
	cout << k << endl;
}

int main()
{
	int num;
	while (cin >> num)
	{
		easy(num);
		vector<int> arr;
		while (num)
		{
			arr.push_back(num % 2);
			num /= 2;
		}

		int i = 0, count = 0, max = 0;
		while (i < arr.size())
		{
			if (arr[i] == 1)
				count++;
			else
			{
				max = count > max ? count : max;
				count = 0;
			}
			i++;
		}
		max = count > max ? count : max;
		cout << max;
	}
}

