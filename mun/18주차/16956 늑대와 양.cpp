// https://www.acmicpc.net/problem/16956

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
#include <tuple>

using namespace std;

int R, C;
char board[501][501];
vector<pair<int, int> > wolfs;

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'W') {
				wolfs.push_back(make_pair(i, j));
			}
		}
	}

	bool impossible = false;
	int nR, nC;

	for (auto wolf : wolfs) {
		// 늑대 4방향 전부 확인하여 가둬버리기
		for (int i = 0; i < 4; ++i) {
			nR = wolf.first + dr[i];
			nC = wolf.second + dc[i];

			if (nR >= 0 && nR < R && nC >= 0 && nC < C) {
				if (board[nR][nC] == '.')
					board[nR][nC] = 'D';
				else if (board[nR][nC] == 'S')
					impossible = true;
			}
		}
	}

	if (impossible)
		cout << 0 << endl;
	else {
		cout << 1 << endl;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}