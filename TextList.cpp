#include <iostream>
using namespace std;

#include "List.h"

#include <vector>

void TestList1()
{
	mine::list<int> L1;

	mine::list<int> L2(10, 5);
	//bite::list<int>::iterator it = L2.begin();
	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;   // 最好用前置++，不是因为后置++不行，实际是以为前置++效率高
	}
	cout << endl;

	vector<int> v{ 1, 2, 3, 4, 5 };
	mine::list<int> L3(v.begin(), v.end());
	for (auto e : L3)
		cout << e << " ";
	cout << endl;

	mine::list<int> L4(L3);
	for (auto e : L4)
		cout << e << " ";
	cout << endl;
}

template<class Iterator ,class T>
Iterator Find(Iterator first, Iterator last, const T& data)
{
	while (first != last)
	{
		if (*first == data)
			return first;
		first++;
	}

	return last;
}

void TestList2()
{
	vector<int> v{ 1,2,3,4,5 };
	mine::list<int> L(v.begin(), v.end());
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	cout << L.size() << endl;

	L.resize(10, 6);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(4);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.push_back(5);
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_back();
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.front() << endl;
	cout << L.back() << endl;

	auto it = Find(L.begin(), L.end(), 2);
	if (it != L.end())
	{
		L.insert(it, 10);
		for (auto e : L)
			cout << e << " ";
		cout << endl;
	}

	L.erase(L.begin(), L.end());
	if (L.empty())
		cout << "erase is ok" << endl;
	else
		cout << "erase is not ok" << endl;
}

int main()
{
	//TestList1();
	TestList2();
	return 0;
}