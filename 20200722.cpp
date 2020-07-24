#include <iostream>
#include <vector>
using namespace std;

//客似云来

int main()
{
	vector<long> v{ 1,1 ,1 };
	for (int i = 3; i <= 80; i++)
	{
		long num = v[i - 1] + v[i - 2];
		v.push_back(num);
	}

	int begin, end;
	while (cin >> begin >> end)
	{
		long count = 0;
		while (begin <= end)
			count += v[begin++];

		cout << count << endl;
	}
	return 0;
}



#if 0

剪花布条

#include <string>


int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		auto it = s1.find(s2);
		if (it != s1.npos)
		{
			while (it != s1.npos)
			{
				count++;
				it += s2.size();
				it = s1.find(s2, it);
			}
			cout << count << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
#endif