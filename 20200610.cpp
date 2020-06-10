#include <iostream>
#include <vector>
using namespace std;

int addAB(int A, int B) {
	int sum = 0, carry = 0;
	while (B != 0)
	{
		//��Ӧλ�ĺ�
		sum = A ^ B;
		//��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ
		carry = (A & B) << 1;
		A = sum;
		B = carry;
	}
	return sum;
}

int fun(int n, int m)
{
	if (n == 0 || m == 0)
		return 1;
	return fun(n - 1, m) + fun(n, m - 1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << fun(n, m);

	return 0;
}

vector<int> getRow(int rowIndex) {

	vector<int> res(rowIndex + 1, 0);
	res[0] = 1;
	for (int i = 1; i < rowIndex + 1; i++)
	{
		for (int j = i; j >= 1; j--)
			res[j] += res[j - 1];
	}

	return res;

}