#include <iostream>
#include <vector>
using namespace std;


//养兔子
int main()
{
	vector<long> v{ 1,1,2 };
	for (int i = 3; i <= 90; i++)
	{
		long num = v[i - 1] + v[i - 2];
		v.push_back(num);
	}
	
	int n = 0;
	while (cin >> n)
	{
		cout << v[n] << endl;
	}

	return 0;
}



#if 0

收件人列表
int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<string> v;
		getchar();
		while (num--)
		{
			string s;
			getline(cin, s);
			v.push_back(s);
		}

		int i = 0;
		for (auto e : v)
		{
			i++;
			if (e.find(' ') != e.npos || e.find(',') != e.npos)
				cout << '"' << e << '"';
			else
				cout << e;

			if (i < v.size())
				cout << ',' << ' ';
		}
		cout << endl;
	}

	return 0;
}
#endif