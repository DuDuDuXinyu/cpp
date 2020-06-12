#if 0
#include <iostream>
using namespace std;

int isprime(int n) 
{ 
	for (int i = 2; i * i <= n; i++)
	{ 
		if (n % i == 0)
			return 0;
	}       
	return 1;
}

int main()
{
	int num;
	while (cin >> num)
	{
		int i = 2;
		while (i < num)
		{
			if (isprime(i))
				if (i % 10 == 1)
					cout << i << " ";
			i++;
		}
		cout << endl;
	}
	return 0;
}
#endif

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string change(string number) {
	int i = 0;
	vector<int> arr;
	while (i < number.size())
	{
		if (isdigit(number[i]))
			if (number[i] % 2 == 0)
				arr.push_back(i);

		i++;
	}

	i = 0;
	int j = arr.size() - 1;
	while (i < j)
	{
		swap(number[arr[i]], number[arr[j]]);
		i++;
		j--;
	}
	return number;
}

int main()
{
	string s("123456");
	cout << change(s);
}