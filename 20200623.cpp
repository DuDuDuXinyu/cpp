#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		string str;
		int now = 1, top, button;

		cin >> str;
		if (n <= 4) {
			top = 1, button = n;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'U') {
					if (now == 1) now = button;
					else now--;
				}
				else {
					if (now == button) now = 1;
					else now++;
				}
			}
		}
		else {
			top = 1, button = 4;
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == 'U') {
					if (now == 1) {
						now = n;
						button = n;
						top = n - 3;
					}
					else if (now == top) {
						now--;
						top--;
						button--;
					}
					else now--;
				}
				else {
					if (now == n) {
						top = 1;
						button = 4;
						now = 1;
					}
					else if (now == button) {
						now++;
						button++;
						top++;
					}
					else now++;
				}
			}
		}
		for (int i = top; i < button; i++)
			cout << i << ' ';
		cout << button << endl;
		cout << now << endl;
	}
	return 0;
}





/*
//洗牌

void wash(vector<int>& s, int n)
{
	vector<int> ret;
	int i = 0;
	while (i <= n)
	{
		ret.push_back(s[i]);
		ret.push_back(s[n + i + 1]);
		i++;
	}
	s = ret;
}

int main()
{
	int T = 0;
	cin >> T;

	while (T--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> s;
		int num = 2 * n;
		while (num--)
		{
			int a;
			cin >> a;
			s.push_back(a);
		}

		while (k--)
			wash(s, n - 1);

		for (auto e : s)
			cout << e << " ";
		cout << endl;
	}
	return 0;
}

int main()
{
	string s;
	while (getline(cin,s))
	{
		int T = s[0] - '0';
		int i = 0;


		while (T--)
		{
			int n = s[i += 2]-'0';
			int k = s[i += 2]-'0';
			string ret;
			int num = 2 * n;
			while (num--)
				ret.push_back(s[i += 2]);

			while (k--)
				wash(ret, n - 1);

			for (auto e : ret)
				cout << e << " ";
		}
	}
	return 0;
}*/



//最长公共字符串的长度
/**
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
*/

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