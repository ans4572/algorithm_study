// https://www.acmicpc.net/problem/16954

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

const int N = 8;
char board[8][8];
int dx[9] = { -1, -1, -1, 0, 0, +1, +1, +1, 0 };
int dy[9] = { -1, 0, +1, -1, +1, -1, 0, +1, 0 };

void blockMove() {
	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j < N; ++j) {
			board[i][j] = board[i - 1][j];
		}
	}
	for (int j = 0; j < N; ++j) {
		board[0][j] = '.';
	}

	return;
}

int blockCount() {
	int count = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == '#')
				count++;
		}
	}

	return count;
}

int main() {
	// input
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j) {
			board[i][j] = s[j];
		}
	}

	queue<pair<pair<int, int>, int> > q;       // 좌표, time
	q.push(make_pair(make_pair(N - 1, 0), 0)); 

	int time = 0;
	bool possible = false;
	while (!q.empty()) {
		if (blockCount() == 0) {
			possible = true;
			break;
		}

		int y = q.front().first.first;
		int x = q.front().first.second;
		int t = q.front().second;

		if (y == 0 && x == N - 1) {
			possible = true;
		}

		// 캐릭터 이동이 끝난 시점 = 다음 큐의 시간이 증가한 경우
		if (time != t) {
			blockMove();
			time++;
		}
		q.pop();

		if (board[y][x] == '#')
			continue;

		for (int d = 0; d < 9; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[ny][nx] == '.') {
				q.push(make_pair(make_pair(ny, nx), t + 1));
			}
		}
	}

	cout << possible << endl;

	return 0;
}