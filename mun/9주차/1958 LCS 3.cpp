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

int dp[101][101][101]; // dp[a][b][c]: ù��°�� a��°, �ι�°�� b��°, ����°�� c��°���� ������ �� LCS ��

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	// ���̰� �ִ� 100 �̹Ƿ� 3�� for�� ����Ͽ� ��ü Ž�� ����
	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			for (int k = 1; k <= c.length(); ++k) {
				// ���� ������ ���
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				// �ƴ� ���
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}

	cout << dp[a.length()][b.length()][c.length()] << endl;

	return 0;
}