#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//最长上升子序列

void mostlong(vector<int>& v)
{
	vector<int> arr(v.size(), 1);
	int sum = 1;
	for (size_t i = 1; i < v.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
			if (v[i] > v[j])
				arr[i] = max(arr[i], arr[j] + 1);

		sum = max(sum, arr[i]);
	}
	cout << sum << endl;
}

int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<int> v(num, 0);
		for (int i = 0; i < num; i++)
			cin >> v[i];

		mostlong(v);
	}

	return 0;
}


/*

发邮件

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long> v{0,0,1,2};
	for(int i = 4; i < 21; i++)
		v.push_back((i-1)*(v[i-1]+v[i-2]));

	int n=0;
	while(cin>>n)
		cout << v[n] << endl;

	return 0;
}

*/