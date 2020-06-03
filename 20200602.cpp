#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;

	vector<int> arr(3 * num, 0);
	for (int k = 0; k < 3 * num; k++)
		cin >> arr[k];

	sort(arr.begin(), arr.end());

	int ret = 0, k = 0;
	while (k < num)
	{
		ret += arr[arr.size() - 2 - (2 * k)];
		k++;
	}
	cout << ret;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2);

	int i = 0, flag = 0;
	while (i<s1.size())
	{
		int k = 0;
		auto it = s1.begin() + i;
		while (k < s2.size())
		{
			if (*it == s2[k++])
			{
				flag = 1;
				break;
			}
				
		}
		if (flag == 1)
		{
			s1.erase(it);
			flag = 0;
		}
		else
			i++;
	}
	cout << s1;
	return 0;
}
#endif 

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int num = 0;
//	cin >> num;
//	
//	vector<int> arr(num,0);
//	for (int i = 0; i < num; i++)
//		cin >> arr[i];
//
//	int i = 0, ret = 0;
//	while (i + 1 < num && arr[i] == arr[i + 1])
//		i++;
//	if (i == num - 1)
//		ret++;
//	while (i + 1 < num)
//	{
//		if (i + 1 < num && arr[i] > arr[i + 1])
//			while(i + 1 < num && arr[i] >= arr[i + 1])
//				i++;
//		else
//			while(i + 1 < num && arr[i] <= arr[i + 1])
//					i++;
//
//		i++;
//		ret++;
//
//		if (i == num - 1)
//			ret++;
//	}
//	cout << ret << endl;
//	return 0;
//}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	string s;
	getline(cin, s);

	auto left = s.begin();
	while (left != s.end())
	{
		auto right= left;
		while (right != s.end() && *right != ' ')
			right++;

		reverse(left,right);

		if (right != s.end())
			left = right + 1;
		else
			left = right;
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}