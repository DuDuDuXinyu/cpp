#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int _min(int a, int b, int c, int d)
{
	return min(min(c, d), min(a, b));
}

bool cinv(vector<vector<char>>& v)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> v[i][j];

	return true;
}

int main()
{
	vector<vector<char>> v(10, vector<char>(10));
	while (cinv(v))
	{
		vector<vector<int>> arr(10, vector<int>(10));
		arr[0][1] = 1;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				int flag = 0;
				if (i == 0 && j == 1)
					continue;

				if (v[i][j] == '.')
				{
					int a = 100, b = 100, c = 100, d = 100;
					if (i - 1 >= 0 && arr[i - 1][j] != 0)
						a = arr[i - 1][j] + 1;
					else if (i + 1 <= 9 && arr[i + 1][j] != 0)
						b = arr[i + 1][j] + 1;
					else if (j - 1 >= 0 && arr[i][j - 1] != 0)
						c = arr[i][j - 1] + 1;
					else if (j + 1 <= 9 && arr[i][j + 1] != 0)
						d = arr[i][j + 1] + 1;

					arr[i][j] = _min(a, b, c, d);

					if (arr[i][j] == 100)
					{
						arr[i][j] = 0;
						flag = 1;
					}
				}

				if (flag)
				{
					for (int j = 9; j >=0; j--)
					{
						if (i == 0 && j == 1)
							continue;

						if (v[i][j] == '.')
						{
							int a = 100, b = 100, c = 100, d = 100;
							if (i - 1 >= 0 && arr[i - 1][j] != 0)
								a = arr[i - 1][j] + 1;
							else if (i + 1 <= 9 && arr[i + 1][j] != 0)
								b = arr[i + 1][j] + 1;
							else if (j - 1 >= 0 && arr[i][j - 1] != 0)
								c = arr[i][j - 1] + 1;
							else if (j + 1 <= 9 && arr[i][j + 1] != 0)
								d = arr[i][j + 1] + 1;

							arr[i][j] = _min(a, b, c, d);
						}
					}
				}
			}
		}
		
		int a, b, c;
		a = arr[9][7] == 0 ? 100 : arr[9][7] + 1;
		b = arr[9][9] == 0 ? 100 : arr[9][9] + 1;
		c = arr[8][8] == 0 ? 100 : arr[8][8] + 1;
		cout << _min(arr[9][8], a, b, c) - 1 << endl;


		for (int i = 0; i < 10; i++)
		{
			for (auto e : arr[i])
			{
				cout << setw(3)<<e;
			}
			cout << endl;
		}
	}

	return 0;
}



/*

½â¶ÁÃÜÂë
int main()
{
	string s;
	while (getline(cin, s))
	{
		for (auto e : s)
		{
			if (e <= '9' && e >= '0')
				cout << e;
		}
		cout << endl;
	}

	return 0;
}
*/