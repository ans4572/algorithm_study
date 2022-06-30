// https://www.acmicpc.net/problem/1520

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int M, N;
int arr[501][501];
int dp[501][501];          // dp[h][w]: (0,0) 에서 (h,w) 까지 올 수 있는 경우의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int DFS(int y, int x) {
	if (y == 0 && x == 0)  //(0,0)지점에 도달하면 1반환
		return 1;
	
	if (dp[y][x] != 0)
		return dp[y][x];

	if (dp[y][x] == -1)
		return 0;

	int ny, nx;
	for (int i = 0; i < 4; ++i) {

		nx = x + dx[i];
		ny = y + dy[i];

		if (ny < 0 || ny >= M || nx < 0 || nx >= N)
			continue;
		if (arr[y][x] >= arr[ny][nx])
			continue;

		int t = DFS(ny, nx);

		if (t > 0)
			dp[y][x] += t;
	}

	if (dp[y][x] == 0)  //(0,0)에 도달하지 못한 곳은 -1로 처리
		dp[y][x] = -1;

	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			DFS(i, j);
		}
	}

	if (dp[M - 1][N - 1] < 0)
		cout << 0 << endl;
	else
		cout << dp[M - 1][N - 1] << endl;

	return 0;
}
