// https://www.acmicpc.net/problem/1958

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int dp[101][101][101]; // dp[a][b][c]: 첫번째는 a번째, 두번째는 b번째, 세번째는 c번째부터 시작할 때 LCS 값

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	// 길이가 최대 100 이므로 3중 for문 사용하여 전체 탐색 진행
	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			for (int k = 1; k <= c.length(); ++k) {
				// 같은 문자인 경우
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				// 아닌 경우
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[a.length()][b.length()][c.length()] << endl;

	return 0;
}