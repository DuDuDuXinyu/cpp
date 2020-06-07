#if 0

#include <iostream>
using namespace std;

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	int num;
	cin >> num;

	int i = 0;
	int left = i;
	while (num >= fib(i))
		left = i++;

	int ret = (num - fib(left)) > (fib(i) - num) ? (fib(i) - num) : (num - fib(left));

	cout << ret;

	return 0;
}
#endif

#if 0
#include <iostream>
#include <stack>
using namespace std;


bool chkParenthesis(string A, int n) {
	if (n % 2 != 0)
		return false;

	stack<char> arr;

	for (auto e : A)
	{
		if (e == '(')
			arr.push(e);
		else if (e == ')')
			if (!arr.empty()&&arr.top() == '(')
				arr.pop();
			else
				return false;
		else
			return false;
		e++;
	}
	if (arr.empty())
		return true;

	return false;
}

int main()
{
	cout << chkParenthesis(")((())", 6) << endl;
	cout << chkParenthesis("()()a()", 7) << endl;
}
#endif

#include <iostream>
using namespace std;

void fun(int a, int b)
{
	if (a == 0)
		if (b == 1)
			cout << 100 << endl;
		else
			cout << 200 << endl;
	else
		cout << 300 << endl;
}
int main()
{
	fun(0, 1);//100
	fun(1, 1);//300
	fun(0, 2);//200
}