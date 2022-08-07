// https://www.acmicpc.net/problem/11062

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int dy[1001][1001];
vector<int> cards;

int play(int left, int right, bool turn) {
	// 게임이 끝난 경우
	if (left > right)
		return 0;

	if (dy[left][right] != 0)
		return dy[left][right];

	if (turn) {
		// 왼쪽에서 뽑고 그 후 플레이 or 오른쪽에서 뽑고 그 후 플레이 의 최대값을 저장
		return dy[left][right] = max(cards[left] + play(left + 1, right, false), cards[right] + play(left, right - 1, false));
	}
	else {
		// 상대방은 왼쪽이나 오른쪽을 뽑고 난 후 최소 값을 저장
		return dy[left][right] = min(play(left + 1, right, true), play(left, right - 1, true));
	}
}

int main() {

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		int N;
		cin >> N;
		cards.resize(N, 0);
		memset(dy, 0, sizeof(dy));

		for (int i = 0; i < N; ++i)
			cin >> cards[i];

		play(0, N - 1, true);
		cout << dy[0][N - 1] << endl;
	}


	return 0;
}