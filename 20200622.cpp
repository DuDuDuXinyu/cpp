
/*空瓶喝水问题

int main()
{
	int emptybottle;
	while (cin >> emptybottle)
	{
		if (0 == emptybottle)
			return 0;

		int bottle = 0;
		while (emptybottle >= 2)
		{
			if (emptybottle == 2)
				emptybottle += 1;

			bottle += emptybottle / 3;
			emptybottle = emptybottle % 3 + emptybottle / 3;
		}
		cout << bottle << endl;
	}
	return 0;
}
*/

/*最长公共子串*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size() > b.size())
			swap(a, b);
		string str_m;//存储最长公共子串
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = i; j < a.size(); j++)
			{
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp)) < 0)
					break;
				else if (str_m.size() < temp.size())
					str_m = temp;
			}
		}
		cout << str_m << endl;
	}
	return 0;
}