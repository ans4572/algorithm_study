#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n,m;
int map[500][500];
int dp[500][500];
bool visited[500][500];
int dir[4][2] = { {1,0},{-1,0} , {0,1},{0,-1} };

int dfs(int x, int y) {   // dp + dfs

	if (x == n - 1 && y == m - 1) return 1; 
	if (visited[x][y]) return dp[x][y];     //이미 방문한 곳은 저장값 리턴
	
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (map[x][y] > map[nx][ny]) {      //작은 곳으로 이동
				dp[x][y] = dp[x][y] + dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false); 	cin.tie(0); 	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout<<dfs(0, 0);

	return 0;
}
