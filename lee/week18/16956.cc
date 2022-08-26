#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> mp(500);
int R, C;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

bool isValidPos(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}

bool chkPossible(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!isValidPos(nr, nc)) continue;
		if (mp[nr][nc] == 'W') return false;
		if (mp[nr][nc] == '.') mp[nr][nc] = 'D';
	}
	return true;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> mp[i];
	}
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (mp[i][j] == 'S') {
				if (!chkPossible(i, j)) {
					cout << "0\n";
					return 0;
				}
			}
		}
	cout << "1\n";
	for (int i = 0; i < R; i++)
		cout << mp[i] << "\n";
	return 0;
}