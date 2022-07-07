#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int n, m, k, cnt;
string word;
char map[101][101];
int dp[101][101][80];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int dfs(int x, int y, int idx) {

	if (dp[x][y][idx] != -1) return dp[x][y][idx];
	if (idx == word.length()) return 1;

	dp[x][y][idx] = 0;

	for (int i = 0; i < 4; i++) {

		int nx = 0, ny = 0;
		for (int j = 1; j <= k; j++) {

			nx = x + j * dir[i][0];
			ny = y + j * dir[i][1];
		
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if (map[nx][ny] == word[idx]) dp[x][y][idx] += dfs(nx, ny, idx + 1);
		}

	}

	return dp[x][y][idx];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
		}
	}

	memset(dp, -1,sizeof(dp));

	cin >> word;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == word[0]) cnt += dfs(i, j, 1);
		}
	}

	cout << cnt;

	return 0;
}
