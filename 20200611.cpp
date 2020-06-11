#if 0
#include <iostream>
#include <vector>
using namespace std;

bool checkWon(vector<vector<int> > board) {
	if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1)
		return true;
	else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1)
		return true;
	else if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1)
		return true;
	else if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1)
		return true;
	else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1)
		return true;
	else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)
		return true;
	else if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
		return true;
	else if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
		return true;
	else
		return false;
}
#endif
#include <iostream>
#include <string>
using namespace std;

int getLen(string& s)
{
	if (s.size() <= 4)
		return 5;
	else if (s.size() >= 8)
		return 25;
	else
		return 10;
}

int getEnglish(string& s)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k<s.size())
	{
		if (isupper(s[k]))
			i = 1;
		if (islower(s[k]))
			j = 1;
		
		k++;
	}
	if (i != 0 && j != 0)
		return 20;
	else if (i != 0 || j != 0)
		return 10;
	else
		return 0;
}

int getNum(string& s)
{
	int k = 0;
	for (auto e : s)
	{
		if (isdigit(e))
			k++;
		e++;
	}
	if (k == 0)
		return 0;
	else if (k == 1)
		return 10;
	else
		return 25;
}

int getSignal(string& s)
{
	int k = 0;
	for (auto e : s)
	{
		if (!isalpha(e) || !isdigit(e))
			k++;
		e++;
	}
	if (k == 0)
		return 0;
	else if (k == 1)
		return 10;
	else
		return 25;
}

int getAward(string& s)
{
	if (getEnglish(s) > 0 && getNum(s) > 0)
	{
		if (getSignal(s) > 0)
		{
			if (getEnglish(s) == 20) // ´óĞ¡Ğ´×ÖÄ¸  ÓĞÊı×Ö£¬ÓĞ·ûºÅ
				return 5;

			return 3; //×ÖÄ¸¡¢Êı×Ö¡¢·ûºÅ
		}
		return 2; // ×ÖÄ¸ºÍÊı×Ö
	}
	return 0;
}

void GetPwdSecurityLevel(string& pPasswordStr)
{

	int res1 = getLen(pPasswordStr);
	int res2 = getEnglish(pPasswordStr);
	int res3 = getNum(pPasswordStr);
	int res4 = getSignal(pPasswordStr);
	int res5 = getAward(pPasswordStr);

	int res = res1 + res2 + res3 + res4 + res5;
	if (res >= 90)
		cout << "VERY_SECURE" << endl;
	else if (res >= 80)
		cout << "SECURE" << endl;
	else if (res >= 70)
		cout << "VERY_STRONG" << endl;
	else if (res >= 60)
		cout << "STRONG" << endl;
	else if (res >= 50)
		cout << "AVERAGE" << endl;
	else if (res >= 25)
		cout << "WEAK" << endl;
	else if (res >= 0)
		cout << "VERY_WEAK" << endl;
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		GetPwdSecurityLevel(s);
	}
	return 0;
}