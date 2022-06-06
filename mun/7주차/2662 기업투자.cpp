// https://www.acmicpc.net/problem/2662

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int arr[21][301];
int dp[21][301];    
int path[21][301];  // dp에 따른 각 기업의 투자 수 저장 배열
int ans[21];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		int money;
		cin >> money;
		for (int j = 1; j <= M; ++j) {
			cin >> arr[j][money];
		}
	}

	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int x = 0; x <= j; ++x) {
				// 이전 기업까지 ( j - x )투자 시 이득 + i번째 기업에 x 금액 투자시 이득
				int value = dp[i - 1][j - x] + arr[i][x];
				if (value > dp[i][j]) {
					dp[i][j] = value;
					path[i][j] = x;
				}
			}
		}
	}

	cout << dp[M][N] << endl;

	// 역추적 진행
	int m = M;
	int n = N;
	for (int i = M; i >= 1; --i) {
		ans[i] = path[m][n];
		m--;
		n -= ans[i];
	}

	for (int i = 1; i <= M; ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}