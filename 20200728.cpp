
//要使用动态规划，注意每个点的概率来源，第一行的点，如(1,3)的概率来源只有它左边点(1,2)的1/2，
//第n行的点如(n,3)，概率来源为(n,2)+(n-1,3)*1/2，因为(n,2)只能往右走，概率为1。其他的特征点在程序段中列出
#include <iostream>
#include <iomanip>
#include<cstring>
using namespace std;


//蘑菇阵

int has[25][25];//有无蘑菇
double dp[25][25];//能够到达每个格子的概率

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

红与黑
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