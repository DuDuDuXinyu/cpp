
//Ҫʹ�ö�̬�滮��ע��ÿ����ĸ�����Դ����һ�еĵ㣬��(1,3)�ĸ�����Դֻ������ߵ�(1,2)��1/2��
//��n�еĵ���(n,3)��������ԴΪ(n,2)+(n-1,3)*1/2����Ϊ(n,2)ֻ�������ߣ�����Ϊ1���������������ڳ�������г�
#include <iostream>
#include <iomanip>
#include<cstring>
using namespace std;


//Ģ����

int has[25][25];//����Ģ��
double dp[25][25];//�ܹ�����ÿ�����ӵĸ���

int main() {
	int n, m, k;
	while (cin >> n >> m >> k) {
		int i, j;
		memset(has, 0, sizeof(has));
		memset(dp, 0, sizeof(dp));
		int x, y;
		for (i = 0; i < k; ++i) {
			cin >> x >> y;
			has[x][y] = 1;
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j) {
				if (i == 1 && j == 1) { dp[1][1] = 1; continue; }
				if (has[i][j]) { dp[i][j] = 0; continue; }
				if (i == n && j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; continue; }
				if (i == n) { dp[i][j] = dp[i - 1][j] * 0.5 + dp[i][j - 1]; continue; }
				if (j == m) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1] * 0.5; continue; }
				if (i == 1) { dp[i][j] = dp[i][j - 1] * 0.5; continue; }
				if (j == 1) { dp[i][j] = dp[i - 1][j] * 0.5; continue; }
				dp[i][j] = dp[i][j - 1] * 0.5 + dp[i - 1][j] * 0.5;
			}
		}
		cout << fixed << setprecision(2) << dp[n][m] << endl;
	}
	return 0;
}

#if 0

�����
int count = 0;

void dfs(vector<vector<char>>& v, int x, int y, int& count)
{
	if (x < 0 || x >= v.size() || y < 0 || y >= v[0].size() || v[x][y] == '#')
		return;

	count++;
	v[x][y] = '#';
	dfs(v, x - 1, y, count);
	dfs(v, x + 1, y, count);
	dfs(v, x, y - 1, count);
	dfs(v, x, y + 1, count);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> v(m, vector<char>(n));

		int x = 0, y = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
				if (v[i][j] == '@')
				{
					x = i;
					y = j;
				}
			}
		}

		int count = 0;
		dfs(v, x, y, count);
		cout << count << endl;
	}

	return 0;
}
#endif