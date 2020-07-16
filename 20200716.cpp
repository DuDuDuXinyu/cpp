#include <iostream>
#include <vector>
using namespace std;


/*

这个好简单啊

void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0, j = 1;
	while (i < len && j < len)
	{
		if (arr[len - 1] % 2 == 0)
		{
			swap(arr[len - 1], arr[i]);
			i += 2;
		}
		else
		{
			swap(arr[len - 1], arr[j]);
			j += 2;
		}
	}
}*/

/*

猴子分桃

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0)
			break;
		else
			cout <<(long)pow(5, n) - 4 <<" "<<(long)pow(4, n) + n - 4 << endl;
	}
	return 0;
}
*/