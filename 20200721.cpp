#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//ì³²¨ÄÇÆõ·ïÎ²
int main()
{
	int n;
	vector<int> fib{ 1,1 };
	for (int i = 2; i <= 100000; i++)
	{
		int num = fib[i - 1] + fib[i - 2];
		num %= 1000000;
		fib.push_back(num);
	}
	while (cin >> n)
	{
		if (n >= 29)
			cout << setfill('0') << setw(6) << fib[n] << endl;
		else
			cout << fib[n] << endl;
	}

	return 0;
}


#if 0

ÌÔ±¦Íøµê

bool IsLeapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;

	return false;
}

bool PrimeNumber(int num)
{
	return num == 2 || num == 3 || num == 5 || num == 7 || num == 11;
}

int main()
{
	int begin_year, begin_month, begin_day;
	int end_year, end_month, end_day;
	vector<int> day_of_month{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> begin_year >> begin_month >> begin_day >> end_year >> end_month >> end_day)
	{
		int money = 0;
		int count_money = 0;
		if (begin_year != end_year)
		{
			if (IsLeapyear(begin_year))
				day_of_month[2] = 29;
			else
				day_of_month[2] = 28;

			money = day_of_month[begin_month] - begin_day + 1;
			if (!PrimeNumber(begin_month))
				money *= 2;

			count_money += money;
			money = 0;

			begin_month++;
			while (begin_month <= 12)
			{
				money = day_of_month[begin_month];
				if (!PrimeNumber(begin_month))
					money *= 2;

				count_money += money;
				money = 0;

				begin_month++;
			}

			begin_year++;
			while (begin_year != end_year)
			{
				if (IsLeapyear(begin_year))
					day_of_month[2] = 29;
				else
					day_of_month[2] = 28;

				int i = 1;
				while (i <= 12)
				{
					money = day_of_month[i];
					if (!PrimeNumber(i))
						money *= 2;

					count_money += money;
					money = 0;

					i++;
				}

				begin_year++;
			}

			int i = 1;
			if (IsLeapyear(begin_year))
				day_of_month[2] = 29;
			else
				day_of_month[2] = 28;
			while (i < end_month)
			{
				money += day_of_month[i];
				if (!PrimeNumber(i))
					money *= 2;

				count_money += money;
				money = 0;

				i++;
			}

			money = end_day;
			if (!PrimeNumber(end_month))
				money *= 2;

			count_money += money;
			money = 0;
		}
		else
		{
			if (IsLeapyear(begin_year))
				day_of_month[2] = 29;
			else
				day_of_month[2] = 28;

			if (begin_month != end_month)
			{
				money = day_of_month[begin_month] - begin_day + 1;
				if (!PrimeNumber(begin_month))
					money *= 2;

				count_money += money;
				money = 0;

				begin_day = 1;
				begin_month++;
			}

			while (begin_month < end_month)
			{
				money = day_of_month[begin_month];
				if (!PrimeNumber(begin_month))
					money *= 2;

				count_money += money;
				money = 0;

				begin_month++;
			}

			money = end_day - begin_day + 1;
			if (!PrimeNumber(begin_month))
				money *= 2;

			count_money += money;
			money = 0;
		}
		
		cout << count_money << endl;
	}
	return 0;
}
#endif