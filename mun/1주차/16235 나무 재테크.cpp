// https://www.acmicpc.net/problem/16235

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, K;
int nourishment[11][11];   // 각 칸의 추가될 양분
int map[11][11];           // 현재 양분
vector<int> trees[11][11];

int dr[8] = { -1, -1, -1, 0, 0, +1, +1, +1 };
int dc[8] = { -1, 0, +1, -1, +1, -1, 0, +1 };

void springAndSummer() {

	vector<int> deadTrees[11][11]; // 죽는 나무들 저장

	// spring
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (trees[i][j].empty())
				continue;

			sort(trees[i][j].begin(), trees[i][j].end());

			for (int k = 0; k < trees[i][j].size(); ++k) {
				// 양분이 충분한 경우
				if (map[i][j] >= trees[i][j][k]) {
					map[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
				}
				// 부족한 경우
				else {
					deadTrees[i][j].push_back(trees[i][j][k]);
					trees[i][j].erase(trees[i][j].begin() + k);
					k--;
				}
			}
		}
	}

	// summer
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k < deadTrees[i][j].size(); ++k) {
				map[i][j] += ( deadTrees[i][j][k] / 2 );
			}
		}
	}

	return;
}

void fall() {

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k < trees[i][j].size(); ++k) {
				if (trees[i][j][k] % 5 == 0) {
					int nr, nc;
					for (int d = 0; d < 8; ++d) {
						nr = i + dr[d];
						nc = j + dc[d];
						if (nr >= 1 && nr <= N && nc >= 1 && nc <= N) {
							trees[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}

	return;
}

void winter() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			map[i][j] += nourishment[i][j];
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> nourishment[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; ++i) {
		int r, c, y;
		cin >> r >> c >> y;
		trees[r][c].push_back(y);
	}

	for (int i = 0; i < K; ++i) {
		springAndSummer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			ans += trees[i][j].size();
		}
	}

	cout << ans << endl;

	return 0;
}