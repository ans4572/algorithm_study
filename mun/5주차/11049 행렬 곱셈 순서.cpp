// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <limits.h>

using namespace std;

int dp[501][501] = { 0 };  // dp[a][b]: a��° ��ĺ��� b��° ��ı��� ������ �� ������ �ּ� Ƚ��
int mat[501][2] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int r, c;
	for (int i = 1; i <= N; ++i) {
		cin >> r >> c;
		mat[i][0] = r;
		mat[i][1] = c;
	}

	for (int m = 1; m < N; ++m) {
		for (int i = 1; i <= N - m; ++i) {
			int j = i + m;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; ++k) {
				// ��ȭ��
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i][0] * mat[k][1] * mat[j][1]);
			}
		}
	}

	cout << dp[1][N] << endl;

	return 0;
}