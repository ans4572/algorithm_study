#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int board[301][301];
int tmp[301][301];
int r, c;
int year;

bool isValidPos(int row, int col) {
	return row >= 0 && row < r&& col >= 0 && col < c;
}

void bfs(int row, int col) {
	queue<pair<int, int>>q;
	tmp[row][col] = 1;
	q.push({ row, col });
	while (!q.empty()) {
		int rr = q.front().first;
		int rc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nr = rr + dr[i];
			int nc = rc + dc[i];
			if (!isValidPos(nr, nc) || tmp[nr][nc] || !board[nr][nc]) continue;
			tmp[nr][nc] = 1;
			q.push({ nr, nc });
		}
	}
}
// 0 0 0
// 1 1 1
//
int countArea() {
	int ret = 0;
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (tmp[i][j] || board[i][j] == 0) continue;
			ret++;
			bfs(i, j);
		}
	return ret;
}

void melt() {
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (!isValidPos(nr, nc)) continue;
				if (board[nr][nc] == 0)cnt++;
			}
			tmp[i][j] = max(0, board[i][j] - cnt);
		}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] = tmp[i][j];
}

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << tmp[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];

	while (1) {
		int cnt = countArea();
		//print();
		if (cnt >= 2) {
			cout << year;
			return 0;
		}
		else if (cnt == 0) {
			cout << 0;
			return 0;
		}
		year++;
		melt();
	}
	return 0;
}
