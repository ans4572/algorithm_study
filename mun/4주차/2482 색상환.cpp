// https://www.acmicpc.net/problem/2482

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int dp[1002][1002];  // dp[a][b]: a�� �� b���� �������� �ʰ� ĥ�ϴ� ����� ��

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 2; j <= N; ++j) {
			// ĥ�ϴ� ��� + ��ĥ�ϴ� ���
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}

	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003 << endl;

	return 0;
}