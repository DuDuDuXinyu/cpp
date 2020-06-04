#include <iostream>
#include <string>
#include <vector>
using namespace std;
#if 0
int main()
{
	string s;
	cin >> s;

	vector<char> arr(256, 0);
	for (auto e : s)
		arr[e]++;

	for (auto e : s)
	{
		if (arr[e] != 0)
		{
			cout << e;
			arr[e] = 0;
		}
	}

	return 0;
}
#endif

#if 0
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int x, y, z;

	x = (a + c) / 2;
	y = (b + d) / 2;
	z = d - y;
	if (x - y == a && y - z == b && x + y == c && y + z == d)
		cout << x << " " << y << " " << z;
	else
		cout << "No";
	return 0;
}
#endif

int main()
{
	int n, m;
	cin >> n >> m;

	vector<char> arr;
	while (n)
	{
		int ret = n % m;
		if(ret==10)
			arr.push_back('A');
		else if (ret == 11)
			arr.push_back('B');
		else if (ret == 12)
			arr.push_back('C');
		else if (ret == 13)
			arr.push_back('D');
		else if (ret == 14)
			arr.push_back('E');
		else if (ret == 15)
			arr.push_back('F');
		else
			arr.push_back(ret+48);
		n = (n - ret) / m;
	}

	for (auto i = arr.rbegin(); i < arr.rend(); i++)
		cout << *i;
	return 0;
}