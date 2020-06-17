
/*
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}
};

class C:public A, public B
{
public:
	C()
	{
		cout << "C" << endl;
	}
	~C()
	{
		cout << "~C" << endl;
	}
};

int main()
{
	A* a = new C();
	delete a;
	return 0;
}*/

#include <iostream>
using namespace std;
/*查看一个数字的bit位有几个1
int main()
{
	int num;
	while (cin >> num)
	{
		int count = 0;
		while (num)
		{
			if ((num & 1) == 1)
				count++;
			num >>= 1; 
		}
		cout << count << endl;
	}
	return 0;
}
*/

/*手套
int sum = 0;
int leftSum = 0, rightSum = 0;
int leftMin = 30, rightMin = 30;
for (int i = 0; i < n; i++)
{
	if (left[i] * right[i] == 0)sum += (left[i] + right[i]);
	else {
		leftSum += left[i];
		rightSum += right[i];
		leftMin = min(leftMin, left[i]);
		rightMin = min(rightMin, right[i]);
	}
}
return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
*/