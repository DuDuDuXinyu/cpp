#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	int arr[] = { 1,2,3,4,5 };
	//注意STL中的所有区间都是左闭右开
	vector<int> v3(arr, arr+sizeof(arr) / sizeof(arr[0]));
	vector<int> v4(arr, arr + 3);
	string s("hello");
	vector<char> v5(s.begin(), s.end());
	vector<int> v6(v3);
	//c++11新增的初始化列表
	vector<int> v7{ 0,0,0,0,0,0 };

	for (auto e : v2)
		cout << e << " ";
	cout << endl;
	for (auto e : v3)
		cout << e << " ";
	cout << endl;
	for (auto e : v4)
		cout << e << " ";
	cout << endl;
	for (auto e : v5)
		cout << e << " ";
	cout << endl;
	for (auto e : v6)
		cout << e << " ";
	cout << endl;
	for (auto e : v7)
		cout << e << " ";
	cout << endl;
}

class Date
{
public:
	Date(int year = 2000, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestVector2()
{
	vector<int> v{ 1,2,3,4,5,6 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(3, 6);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.reserve(20);	//没有传递第二个参数的时候，使用的是默认值0来填充的
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;	

	v.reserve(8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	Date d(2020, 5, 21);
	vector<Date> vd;
	vd.resize(10, d);
	vd.resize(20);
	// 第二个参数如果没有传递，编译器会调用Date()来构造一个匿名对象进行填充
	// 类中一点定义了构造函数，编译器将不会在生成无参的构造函数
}

void TestVector3()
{
	vector<int> v1;
	v1.reserve(10);

	//该行代码崩溃，因为reserv只是扩容，有效元素依旧是0，所以访问的时候会崩溃
	//cout << v1[0] << endl;
	
	vector<int> v2;
	v2.resize(10);
	cout << v2[0] << endl;
}

void TestVector4()
{
	vector<int> v;
	size_t sz = v.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << sz << endl;
		}
	}
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	vector<int> vv;
	vv.reserve(100);
	size_t szz = vv.capacity();
	for (size_t i = 0; i < 100; i++)
	{
		vv.push_back(i);
		if (szz != vv.capacity())
		{
			szz = vv.capacity();
			cout << szz << endl;
		}
	}
	for (auto e : vv)
		cout << e << " ";
	cout << endl;

	Date d(2020, 5, 17);
	vector<Date> vd;
	vd.push_back(d);

	// C++11: 提供就地构造
	vd.emplace_back(2020, 5, 18);
}

void TestVector5()
{
	vector<int> v{ 1,2,3,4,5 };
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	//在3的前面插入0
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
		v.insert(pos, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.begin(), 5, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	vector<int> vv{ 11,22,33 };
	v.insert(v.end(), vv.begin(), vv.end());
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.end(), { 100,200,300 });
	
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector6()
{
	vector<int> v1{ 1,2,3,4,5 };
	v1.erase(v1.begin());
	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	vector<int> v2{ 1,2,3,4,5 };
	v2.clear();
	for (auto e : v2)
		cout << e << " ";
	cout << endl;
	vector<int> v3{ 1,2,3,4,5 };
	v3.erase(v3.begin(), v3.end());
	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}

void TestVector7()
{
	Date d(2020, 5, 20);
	vector<Date> v;
	v.reserve(10);

	//插入的是对象的拷贝
	v.push_back(d);

	//就地构造
	v.emplace_back(2020.5,21);
}

void TestVector8()
{
	vector<int> v;
	v.reserve(100);
	size_t sz = v.capacity();
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << sz << endl;
		}
	}
}

void TestVector9()
{
	vector<int> v{ 1,2,3,4,5 };
	v.insert(v.begin() + 2, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.begin(), 5, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	vector<int> vv{ 6,7,8 };
	v.insert(v.end(), vv.begin(), vv.end());
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.end(), { 9,0 });
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector10()
{
	vector<int> v{ 1,2,3,4,5 ,6,7,8,9 };
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	auto it = find(v.begin(), v.end(), 3);
	if (it != v.end())
		v.erase(it);

	v.erase(v.begin());
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin() + 2);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin(), v.begin() + 3);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.begin(), v.end());
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector11()
{
	vector<int> v{ 1,2,3,4,5 };
	auto it = v.begin();

	//扩容导致迭代器失效
	v.push_back(6);
	v.push_back(7);

	v.assign(10, 5);

	//重新个it赋值到新空间的首地址就可以正常使用
	it = v.begin();

	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void TestVector12()
{
	vector<int> v{ 9,33,1,2,3,4,5,6,7,8,9,0 };

	//将vector中的所有的偶数都删除
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			it++;
	}
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

void TestVector13()
{
	vector<vector<int>> v1;
	v1.resize(5);

	cout << v1[0].size() << endl;
	cout << v1[0].capacity() << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		v1[i].resize(6);
		for (size_t j = 0; j < v1[i].size(); j++)
			v1[i][j] = j + 1;
	}

	for (auto vrow : v1)
	{
		for (auto e : vrow)
			cout << e << " ";
		cout << endl;
	}


	vector<vector<int>> v2(5, vector<int>(6, 10));
	for (auto vrow : v2)
	{
		for (auto e : vrow)
			cout << e << " ";
		cout << endl;
	}
}

void TestVector14()
{
	vector<vector<int>> vv(5);

	for (size_t i = 0; i < vv.size(); i++)
	{
		vv[i].resize(i+1,1);
		for (size_t j = 1; j < i; j++)
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
	}

	for (auto vrow : vv)
	{
		for (auto e : vrow)
			cout << e << " ";
		cout << endl;
	}
}

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	//TestVector6();
	//TestVector7();
	//TestVector8();
	TestVector14();
	return 0;
}