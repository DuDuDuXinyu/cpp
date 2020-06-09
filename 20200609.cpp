#if 0
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int lenflag, flag;

	string s[100];

	int i = 0;
	while (i < n)
		cin >> s[i++];

	int j = 0;
	while (j + 1 < n && s[j].size() < s[j + 1].size())
		j++;
	if (j + 1 == n)
		lenflag = 1;

	j = 0;
	while (j + 1 < n && s[j].compare(s[j + 1]) <= 0)
		j++;
	if (j + 1 == n)
		flag = 1;

	if (flag == lenflag && flag == 1)
		cout << "both" << endl;
	else if (flag == 1)
		cout << "lexicographically" << endl;
	else if (lenflag == 1)
		cout << "lengths" << endl;
	else
		cout << "none" << endl;
}
#endif

#include <iostream>
using namespace std;

int gcd(int n,int m)
{
	return m == 0 ? n : gcd(m, n % m);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << n * m / gcd(n, m);
}