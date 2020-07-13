/*

int GCD(int n, int m)
{
	if (n < m)
		swap(n, m);

	while (m != 0)
	{
		int temp = n % m;
		n = m;
		m = temp;
	}
	return n;
}

int main()
{
	int a = 0, num = 0;
	while (cin >> num >> a) 
	{
		vector<int> v;
		int temp = 0;
		while (num--)
		{
			cin >> temp;
			v.push_back(temp);
		}
		for (auto e : v)
		{
			if (e <= a)
				a += e;
			else
				a += GCD(a, e);
		}

		cout << a << endl;
	}
	return 0;
}*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<int> v(256, 0);
	for (auto e : s)
		v[e]++;
	for (int i = 0; i < s.size(); i++)
	{
		if (v[s[i]] == 1)
		{
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}