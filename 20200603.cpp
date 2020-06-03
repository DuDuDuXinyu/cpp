

#if 0
int main()
{
	string s;
	cin >> s;

	int i = 0;
	int pos = 0, max = 0, count = 0;
	while (i < s.size())
	{

		while (i < s.size() && s[i] < '0' || s[i] > '9')
			i++;
		while (i < s.size() && s[i] >= '0' && s[i] <= '9')
			count++, i++;

		if (count > max)
		{
			max = count;
			pos = i - count;
		}

		count = 0;
	}

	for (int j = pos; j < pos + max; j++)
		cout << s[j];
	cout << endl;

	return 0;
}
#endif
#include <iostream>
#include <vector>
using namespace std;

/*int MoreThanHalfNum_Solution(vector<int> numbers) {
	
	int max = numbers[0];
	for (int i = 1; i < numbers.size(); i++)
		max = numbers[i] > max ? numbers[i] : max;

	int num = numbers.size() % 2 == 0 ? numbers.size() / 2 : numbers.size() / 2 + 1;
	vector<int> ret(max, num);

	for (int i = 0; i < numbers.size(); i++)
	{
		ret[numbers[i]-1]--;
		if (ret[numbers[i]-1] == 0)
			return numbers[i];
	}
	return 0;
}*/

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int ret = 1, value = numbers[0];
	for (int i = 1; i < numbers.size(); i++)
	{
		if (numbers[i] == value)
			ret++;
		else
		{
			ret--;
			if (ret < 0)
			{
				value = numbers[i];
				ret = 1;
			}
		}
	}
	if (ret > 0)
		return value;
	else
		return 0;
}

int main()
{
	int myints[] = { 1,2,3,2,2,2,5,4,2 };
	vector<int> arr(myints, myints + sizeof(myints) / sizeof(int));
	int ret = MoreThanHalfNum_Solution(arr);
	cout << ret;
	return 0;
}