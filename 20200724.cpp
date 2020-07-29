
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//抄送列表
using namespace std;
int main()
{
	string str, name;
	while (getline(cin, str))
	{
		getline(cin, name);
		//接下来把抄送列表分割
		vector<string>v;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == '\"') {//处理有引号的部分
				v.push_back(str.substr(i + 1, str.find('\"', i + 1) - i - 1));
				i = str.find('\"', i + 1) + 1;
			}
			else {//处理非引号部分
				if (str.find(',', i) == str.npos) {
					v.push_back(str.substr(i, str.size() - i));
					i = str.size();
				}
				else {//没到结束
					v.push_back(str.substr(i, str.find(',', i) - i));
					i = str.find(',', i);
				}
			}
		}
		cout << ((find(v.begin(), v.end(), name) != v.end()) ? "Ignore" : "Important!") << endl;
	}
	return 0;
}

/*

年会抽奖

#include<stdio.h>
int main()
{
	long long der[21] = { 0,0,1 }, fun[21] = { 0,1,2 };
	int i, n;
	for (i = 3; i < 21; i++)
	{
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
		fun[i] = i*fun[i - 1];
	}
	while (~scanf("%d", &n))
	{
		printf("%.2f%c\n", 1.0*der[n] /fun[n] * 100, '%');
	}
	return 0;
}

*/