#if 0
#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
	{
		cout << a << endl;
	}
	~A(){}
};
class B:virtual public A
{
public:
	B(int a,int b)
		:A(a)
	{
		cout << b << endl;
	}
	~B() {}
};
class C :virtual public A
{
public:
	C(int a, int b)
		:A(a)
	{
		cout << b << endl;
	}
	~C() {}
};

class D :public B, public C
{
public:
	D(int a, int b,int c,int d)
		:B(a,b)
		,C(a,c)
		,A(a)
	{
		cout << d << endl;
	}
	~D() 
	{
	}
};

int main()
{
	D d(1, 2, 3, 4);
}
#endif



#if 0
class A
{
public:
	int bar(char a)
	{
		return (int)(a);
	}
	virtual int bar(int a)
	{
		return (2 * a);
	}
};
class B:public A
{
public:
	int bar(char a)
	{
		return (int)(-a);
	}
	virtual int bar(int a)
	{
		return (a / 2);
	}
};

void fun(const int& a, const int& b)
{
	cout << a << " " << b << endl;
}

int main()
{
	int i = 0;
	fun(++i, i++);

	B b;
	b.bar(1000);
	A* a = &b;
	cout << a->bar(char(100)) << endl;
	cout << a->bar(100);
	return 0;
}

#endif

#if 0
#include <iostream>
#include <vector>
using namespace std;

int easy(int n, int m, int j, int i) 
{
	m <<= j;
	return n | m;
}

int main()
{
	int n, m, i, j;
	while (cin >> n >> m >> i >> j)
	{
		vector<int> arrn;
		while (n)
		{
			arrn.push_back(n % 2);
			n /= 2;
		}

		for (auto e : arrn)
			cout << e;
		cout << endl;

		vector<int> arrm;
		while (m)
		{
			arrm.push_back(m % 2);
			m /= 2;
		}

		for (auto e : arrm)
			cout << e;
		cout << endl;
		

		for (int e = i,y=0; y < arrm.size(); e++,y++)
		{
			arrn[e] = arrm[y];
		}

		for (auto e : arrn)
			cout << e;
		cout << endl;

		int ret = 0, k = arrn.size() - 1;
		while (k >= 0)
			ret = ret * 2 + arrn[k--];
		return ret;
	}
	return 0;
}

#endif

#include <iostream>
#include <vector>
using namespace std;

int isprime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int num;
	cin >> num;
	vector<int> arr;
	int i = 2;
	while (i < num)
	{
		if (isprime(i))
			arr.push_back(i);
		i++;
	}
	int left = 0, right = 0, mid = 10000;
	for (int i = 0; i <arr.size() ; i++)
	{
		int j = i;
		for (; j < arr.size(); j++)
		{
			if (arr[i] + arr[j] > num)
				break;
			else if (arr[i] + arr[j] < num)
				continue;
			else
			{
				
				if (mid > (arr[j] - arr[i]))
				{
					left = arr[i];
					right = arr[j];
					mid = right - left;
				}
			}
		}
	}
	cout << left << " " << right;
	return 0;
}
//还有一个方法就是从n/2的位置开始
//然后i--，n-i然后如果都是素数就是答案
