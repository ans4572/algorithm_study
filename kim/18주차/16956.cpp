#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int r, c;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
char table[501][501];
vector<pair<int, int>> wolf;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> table[i][j];
			if (table[i][j] == 'W') wolf.push_back({ i,j });
		}
	}

	for (auto pos : wolf) {
		int x = pos.first;
		int y = pos.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

			if (table[nx][ny] == '.') table[nx][ny] = 'D';	// 울프가 다니는 길은 모두 울타리 침.
			else if (table[nx][ny] == 'S') {	// 상하좌우에 s가 있다는 뜻은 울프와 붙어있다는 뜻. 무조건 0이 될 수 밖에 없다.
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1 << "\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << table[i][j];
		}cout << "\n";
	}

	return 0;
}
