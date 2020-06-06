#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));
	vector<int> ret;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i - 2 >= 0 && arr[i - 2][j] == 1)
				continue;
			if (i + 2 < n && arr[i + 2][j] == 1)
				continue;
			if (j - 2 >= 0 && arr[i][j - 2] == 1)
				continue;
			if (j + 2 < m && arr[i][j + 2] == 1)
				continue;
			arr[i][j] = 1;
			count++;
		}
	}

	cout << count;
	for (auto e = arr.begin(); e < arr.end(); e++)
	{
		ret = *e;
		for (auto it = ret.begin(); it < ret.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
		
	return 0;
}
#endif
#if 0
int StrToInt(string str) {
	if (str[0] <= '9' && str[0] >= '0' || str[0] == '+' && str[0] == '-')
	{
		int i = 1; 
		while (i < str.size())
		{
			if (str[i] <= '9' && str[i] >= '0')
				i++;
			else
				return 0;
		}
	}
	int ret=0;

	int i = 0, flag = 1;
	while (i < str.size())
	{
		if (str[0] == '-')
			flag = -1, i++;
		if (str[i] <= '9' && str[i] >= '0')
		{
			ret += (str[i] - 48) * pow(10, str.size() - 1 - i);
			i++;
		}
		else
			return 0;
	}
	return ret;
}

#endif

int StrToInt(string str)
{
	if (str.empty())
		return 0;

	int flag = 1;
	if (str[0] == '-')
		flag = -1, str[0] = '0';

	int ret = 0;
	/*for (auto it = str.begin(); it < str.end(); it++)
	{
		if (*it < '0' || *it > '9')
			return 0;

		ret = ret * 10 + *it - '0';
	}*/


		for (int i = 0; i < str.size(); ++i) {
			if (str[i] < '0' || str[i] > '9') {
				ret = 0;
				break;
			}

			ret = ret * 10 + str[i] - '0';

		}
	return ret * flag;
}
int main()
{
	cout << StrToInt("123456");
	return 0;
}