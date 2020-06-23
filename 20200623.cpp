#include <iostream>
#include <string>
using namespace std;

//最长公共字符串的长度

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() > s2.size())
			swap(s1, s2);
			
		int i = 0, max = 0;
		while (i < s1.size())
		{
			auto it = s2.find(s1[i]);
			while (it != string::npos)
			{
				int k = (int)it;
				int j = i, count = 0;
				while (j < s1.size() && s2[k++] == s1[j++])
					count++;

				max = max > count ? max : count;

				it = s2.find(s1[i],it+1);
			}
			i++;
		}
		cout << max << endl;
	}
	return 0;
}

/*逆置字符串
int main()
{
	string s;
	while (cin >> s)
	{
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}*/