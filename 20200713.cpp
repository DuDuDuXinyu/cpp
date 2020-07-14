
#if 0
int main()
{
	int a = 0x12345678;
	return 0;
}
#endif 


#if 0 
星际密码
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
	vector<int> v{ 1,1 };
	for (int i = 2; i < 10001; ++i)
		v.push_back((v[i - 2] + v[i - 1]) % 10000);

	int num;
	while (cin >> num)
	{
		while (num--)
		{
			int x = 0;
			cin >> x;
			cout<< setw(4) << setfill('0') << v[x];
		}
		cout << endl;
	}

	return 0;
}

#endif

#if 0

数根
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		int num = 0;
		//先将每一位进行相加得到总和，防止数字过大
		for (int i = 0; i < str.size(); ++i) {
			num += str[i] - '0';
		}
		int sum = 0;
		while (num) {
			sum += num % 10;
			num /= 10;
			if (num == 0 && sum / 10 != 0) {
				num = sum;
				sum = 0;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
#endif