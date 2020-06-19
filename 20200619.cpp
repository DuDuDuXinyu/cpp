
/*
INOC—产品部 杨辉三角的变形

int main()
{
	int num;
	while (cin >> num)
	{
		if (num <= 2)
		{
			cout << -1 << endl;
			continue;
		}
		
		vector<vector<int>> arr(num, vector<int>(2 * num - 1));
		arr[0][num - 1] = 1;
		arr[1][num - 1] = arr[1][num] = arr[1][num - 2] = 1;

		int k = 3;

		while (k < num)
		{
			int i = num - k;
			int ret = i + 2 * k - 1;
			while (i < ret)
			{
				arr[k - 1][i] = arr[k - 2][i] + arr[k - 2][i - 1] + arr[k - 2][i + 1];
				i++;
			}
			k++;
		}
		
		int e = 0;
		while (e < num)
		{
			if (e - 1 < 0)
				arr[num - 1][e] = arr[num - 2][e] + arr[num - 2][e + 1];
			else if (e + 1 > num - 1)
				arr[num - 1][e] = arr[num - 2][e] + arr[num - 2][e - 1];
			else
				arr[num - 1][e] = arr[num - 2][e] + arr[num - 2][e - 1] + arr[num - 2][e + 1];

			if (arr[num - 1][e] % 2 == 0)
			{
				cout << e + 1 << endl;
				break;
			}
			e++;
		}
	}
	return 0;
}*/


/*超长正整数相加

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<int> arr1;
		vector<int> arr2;

		for (auto e : s1)
			arr1.push_back(e);
		for (auto e : s2)
			arr2.push_back(e);

		string ret;
		int i = 0, flag = 0;
		int max = arr1.size() > arr2.size() ? arr1.size() : arr2.size();
		int arr1end = arr1.size() - 1;
		int arr2end = arr2.size() - 1;
		while (i++ < max)
		{
			int num = 0;
			if (arr1end >= 0 && arr2end >= 0)
				num = arr1[arr1end--] + arr2[arr2end--] + flag - '0' - '0';
			else if (arr1end >= 0)
				num = arr1[arr1end--] + flag - '0';
			else
				num = arr1[arr2end--] + flag - '0';

			if (num <= 9)
			{
				ret.push_back(num+'0');
				flag = 0;
			}
			else
			{
				ret.push_back(num % 10+'0');
				flag = 1;
			}
		}

		if (flag == 1)
			ret.push_back('1');

		for (auto i = ret.rbegin(); i < ret.rend(); i++)
			cout << *i;
		cout << endl;
		
	}
	return 0;
}
*/

//简单版

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int temp = 0, carry = 0;
		while (a.size() < b.size())
			a = "0" + a;
		while (a.size() > b.size())
			b = "0" + b;
		for (int i = a.size() - 1; i >= 0; i--)
		{

			temp = a[i] - '0' + b[i] - '0' + carry;
			a[i] = temp % 10 + '0';
			if (temp / 10)
				carry = 1;
			else
				carry = 0;
		}
		if (carry)
			a = "1" + a;
		cout << a << endl;
	}
	return 0;
}