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

int board[21][21];
int dx[5] = {0, 0, 0, -1 ,1};
int dy[5] = {0, 1, -1, 0, 0};

int main() {
	int n, m, x, y, k;
	
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	vector<int> input(k);
	for (int i = 0; i < k; ++i)
		cin >> input[i];

	vector<int> dice = { 0, 0, 0, 0, 0, 0 }; // 윗면, 뒷면, 바닥면, 앞면, 왼쪽면, 오른쪽면 순서
	for (int i = 0; i < k; ++i) {

		int nx = x + dx[input[i]];
		int ny = y + dy[input[i]];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		vector<int> nDice;  // 임시 저장

		if (input[i] == 1)
			nDice = { dice[4], dice[1], dice[5], dice[3], dice[2], dice[0] };
		else if (input[i] == 2)
			nDice = { dice[5], dice[1], dice[4], dice[3], dice[0], dice[2] };
		else if (input[i] == 3)
			nDice = { dice[3], dice[0], dice[1], dice[2], dice[4], dice[5] };
		else 
			nDice = { dice[1], dice[2], dice[3], dice[0], dice[4], dice[5] };

		dice = nDice;

		// 복사 과정 진행
		if (board[nx][ny] == 0)
			board[nx][ny] = dice[2];
		else {
			dice[2] = board[nx][ny];
			board[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << dice[0] << "\n";
	}

	return 0;
}