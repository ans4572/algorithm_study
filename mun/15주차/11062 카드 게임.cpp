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
	// ������ ���� ���
	if (left > right)
		return 0;

	if (dy[left][right] != 0)
		return dy[left][right];

	if (turn) {
		// ���ʿ��� �̰� �� �� �÷��� or �����ʿ��� �̰� �� �� �÷��� �� �ִ밪�� ����
		return dy[left][right] = max(cards[left] + play(left + 1, right, false), cards[right] + play(left, right - 1, false));
	}
	else {
		// ������ �����̳� �������� �̰� �� �� �ּ� ���� ����
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