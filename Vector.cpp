#include <iostream>
#include <vector>
#include <string>

using namespace std;

void TestVector1()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	int arr[] = { 1,2,3,4,5 };
	//ע��STL�е��������䶼������ҿ�
	vector<int> v3(arr, arr+sizeof(arr) / sizeof(arr[0]));
	vector<int> v4(arr, arr + 3);
	string s("hello");
	vector<char> v5(s.begin(), s.end());
	vector<int> v6(v3);
	//c++11�����ĳ�ʼ���б�
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

	v.reserve(20);	//û�д��ݵڶ���������ʱ��ʹ�õ���Ĭ��ֵ0������
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
	// �ڶ����������û�д��ݣ������������Date()������һ����������������
	// ����һ�㶨���˹��캯�����������������������޲εĹ��캯��
}

void TestVector3()
{
	vector<int> v1;
	v1.reserve(10);

	//���д����������Ϊreservֻ�����ݣ���ЧԪ��������0�����Է��ʵ�ʱ������
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

	// C++11: �ṩ�͵ع���
	vd.emplace_back(2020, 5, 18);
}

void TestVector5()
{
	vector<int> v{ 1,2,3,4,5 };
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	//��3��ǰ�����0
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

int main()
{
	//TestVector1();
	//TestVector2();
	//TestVector3();
	//TestVector4();
	//TestVector5();
	TestVector6();
	return 0;
}