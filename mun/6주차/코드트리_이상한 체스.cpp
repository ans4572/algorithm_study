// https://www.codetree.ai/frequent-problems/cube-rounding/description

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

int N, M;
int board[9][9];
vector<pair<int, int>> vec;  // 말의 좌표 저장 배열
bool visit[9][9];            // 방문 저장
int ans = 100;
int dn[4] = { 1, -1, 0, 0 };
int dm[4] = { 0, 0, 1, -1 };

// 종류에 따른 이동 방향
vector<vector<int>> piece = {
	{},
	{1, 0, 0, 0},
	{0, 1, 0, 1},
	{1, 1, 0, 0},
	{1, 1, 0, 1},
	{1, 1, 1, 1}
};

// 한 방향으로 쭉 이동시키는 함수
// (n,m): 좌표 / d: 방향
void move(int n, int m, int d) {
	visit[n][m] = true;

	int nn = n + dn[d];
	int mm = m + dm[d];

	while (true) {
		// 범위 벗어난 경우
		if (nn < 0 || nn >= N || mm > 0 || mm >= M)
			break;

		visit[nn][mm] = true;

		// 상대방 체스 만난 경우
		if (board[nn][mm] == 6) 
			break;
		
		nn += dn[d];
		mm += dm[d];
	}

	return;
}

void chess(int idx, vector<int> &dir) {
	if (idx == vec.size()) {

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < vec.size(); ++i) {
			int n = vec[i].first;
			int m = vec[i].second;

			// 말의 앞 방향에 따른 이동할 수 있는 격자 범위 정하면서 이동
			for (int d = 0; d < 4; ++d) {
				go[d + dir] = piece[board[n][m]][(d + dir[i]) % 4];
			}

		}

		int count = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if(!visit[i][j]) count++;
			}
		}

		ans = min(ans, count);

		return;
	}
	else {
		// 각 말마다 4방향으로 진행 
		for (int i = 0; i < 4; ++i) {
			dir[idx] = i;
			chess(idx + 1, dir);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];

			if (board[i][j] > 0 && board[i][j] != 6) 
				vec.push_back(make_pair(i,j));
		}
	}

	vector<int> dir(vec.size(), 0);

	chess(0, dir);

	cout << ans << endl;

	return 0;
}