// https://www.acmicpc.net/problem/17404

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int dy[1001][3];       // i번째 집을 빨강,초록,파랑으로 칠하는 최소 비용
int rgb[1001][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) 
		for (int j = 0; j < 3; ++j)
			cin >> rgb[i][j];

	int ans = 10000000;

	// 1번집 색을 고정으로 총 3색을 진행
	for (int i = 0; i < 3; ++i) {

		for (int j = 0; j < 3; ++j) {
			// 색 고정
			if (i == j)
				dy[1][j] = rgb[1][j];
			else
				dy[1][j] = 10000000;
		}

		// 이전 집과 다른 색으로 칠하기
		for (int j = 2; j <= N; ++j) {

			dy[j][0] = min(dy[j - 1][1], dy[j - 1][2]) + rgb[j][0];
			dy[j][1] = min(dy[j - 1][0], dy[j - 1][2]) + rgb[j][1];
			dy[j][2] = min(dy[j - 1][0], dy[j - 1][1]) + rgb[j][2];
		}

		// 1번집과 다른 색은 정답 가능하므로 비교 진행
		for (int j = 0; j < 3; ++j) {
			if (i != j)
				ans = min(ans, dy[N][j]);
		}
	}

	cout << ans << endl;

	return 0;
}
