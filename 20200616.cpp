#if 0
#include <iostream>
using namespace std;


int main()
{
	int n = 197;
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);//133
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);//34
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);//4
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);//4
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);//4
	cout << n;//4
	return 0;
}

#endif

//��һ������һ��ĵڼ���
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int year, month, day;
//	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (cin >> year >> month >> day)
//	{
//		if (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0))
//			days[2] = 29;
//		else
//			days[2] = 28;
//
//		int i = 1, ret = 0;
//		while (i < month)
//			ret += days[i++];
//
//		ret += day;
//
//		if (month > 12 || month<0 || day>days[month])
//			ret = -1;
//
//		cout << ret << endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <set>
//using namespace std;
//
//
//
//void fun(multiset<int> arr,int* count)
//{
//	int flag = 1;
//	while (flag)
//	{
//		int he = 0;
//		int chengji = 1;
//		for (auto e : arr)
//		{
//			he += e;
//			chengji *= e;
//		}
//
//		if (chengji < he)
//			*count++;
//
//		arr.erase(--arr.end());
//
//		if (arr.size() == 1)
//			flag = 0;
//	}
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		multiset<int> arr;
//
//		int i = 0;
//		while (i < n)
//		{
//			int num;
//			cin >> num;
//			arr.insert(num);
//			i++;
//		}
//
//		int count = 0;
//		i = 0;
//		int  k = arr.size();
//		while (i < k)
//		{
//
//			fun(arr, &count);
//			auto it = arr.end();
//			it--;
//			arr.erase(--arr.end());
//			fun(arr, &count);
//			arr.insert(*it);
//			i++;
//		}
//		cout << count << endl;;
//	}
//}

/*���˵Ĵ���

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cont = 0;
void ContOne(int, vector<int>, int, int, int); //��1�ĸ�������1������ǰλ��, ��, ����
int main(void)
{
	int n, numb, OneCont(0);        //OneCont������¼1���ܸ���
	vector<int> list;
	cin >> n;
	while (n--)
	{
		cin >> numb;
		if (numb > 1)
			list.push_back(numb);
		else
			OneCont++;
	}
	cont = OneCont - 1; //����1�����ȼ������
	if (!list.empty())
	{
		sort(list.begin(), list.end()); //����������
		for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
	}
	cout << cont << endl;
	return 0;
}
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
{
	for (int i = nowBit; i < list.size(); i++) //������������
	{
		sum += list[i], mult *= list[i];
		if (sum <= mult) //��������ϣ���������һλ
			break;
		else
			cont++;
		ContOne(OneNub, list, i + 1, sum, mult);
		sum -= list[i], mult /= list[i]; //�ص���һλ����Ҫ�ָ���ֵ
		while (i < list.size() - 1 && list[i] == list[i + 1])
			i++;  //Ѱ�Ҳ��ظ�
	}
}
*/