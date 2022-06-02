// https://www.codetree.ai/frequent-problems/tail-catch-play/description

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
vector<pair<int, int>> lines[5];  // 각 팀의 이동 선 정보
deque<pair<int, int>> team[5];    // 각 팀원들 위치, front : 머리사람 / back : 꼬리사람
int headIdx[5] = { 0 };           // 각 팀 이동 선 배열에서 헤드 인덱스 저장 
bool isReverse[5];                  
int N, M, K;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int score = 0;

// 각 팀별 이동 선 찾는 함수
// 처음 한번만 실행
// BFS 활용
void findLines() {
	int idx = 0;
	bool visit[21][21] = { false };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			
			// 머리 사람을 기준으로 시작
			if (board[i][j] == 1 && !visit[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });

				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					lines[idx].push_back({ r,c });
					visit[r][c] = true;

					if (board[r][c] < 4)
						team[idx].push_back({ r,c });

					q.pop();

					for (int i = 0; i < 4; ++i) {
						int nr = r + dr[i];
						int nc = c + dc[i];

						if(nr >= 0 && nr < N && nc >=0 && nc < N && !visit[nr][nc] && board[nr][nc] > 0) {
							if (board[r][c] == 1 && board[nr][nc] == 2) {
								q.push({ nr,nc });
								break;
							}
							else if (board[r][c] == 1 && board[nr][nc] != 2)
								continue;
							else {
								q.push({ nr,nc });
								break;
							}
						}
					}
				}

				idx++;
			}
		}
	}

	return;
}

// 각 라운드마다 팀 이동 함수
void moveLines() {
	
	for (int i = 0; i < M; ++i) {

		if (!isReverse[i]) {
			if (headIdx[i] == 0)
				headIdx[i] = lines[i].size() - 1;
			else
				headIdx[i] -= 1;
		}
		else {
			if (headIdx[i] == lines[i].size() - 1)
				headIdx[i] = 0;
			else
				headIdx[i] += 1;
		}

		board[team[i].front().first][team[i].front().second] = 2;
		team[i].push_front(lines[i][headIdx[i]]);
		board[team[i].front().first][team[i].front().second] = 1;

		board[team[i].back().first][team[i].back().second] = 4;
		team[i].pop_back();
		board[team[i].back().first][team[i].back().second] = 3;
	}

	return;
}

int main() {

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}

	findLines();

	for (int i = 0; i < K; ++i) {

		moveLines();

		int d = i % (N * 4);
		bool find = false;
		if (d / N == 0) {
			for (int j = 0; j < N; ++j) {
				if (board[d % N][j] > 0 && board[d % N][j] < 4) {
					int r = d % N;
					int c = j;

					for (int t = 0; t < M; ++t) {
						for (int p = 0; p < team[t].size(); ++p) {
							if (team[t][p].first == r && team[t][p].second == c) {
								score += pow(p + 1, 2);
								isReverse[t] = !isReverse[t];
								reverse(team[t].begin(), team[t].end());
								find = true;
								break;
							}
						}

						if (find)
							break;
					}
				}
				if (find)
					break;
			}
		}
		else if (d / N == 1) {
			for (int j = N - 1; j >= 0; --j) {
				if (board[j][d % N] > 0 && board[j][d % N] < 4) {
					int r = j;
					int c = d % N;

					bool find = false;

					for (int t = 0; t < M; ++t) {
						for (int p = 0; p < team[t].size(); ++p) {
							if (team[t][p].first == r && team[t][p].second == c) {
								score += pow(p + 1, 2);
								isReverse[t] = !isReverse[t];
								reverse(team[t].begin(), team[t].end());
								find = true;
								break;
							}
						}

						if (find)
							break;
					}
				}
				if (find)
					break;
			}
		}
		else if (d / N == 2) {
			for (int j = N - 1; j >= 0; --j) {
				if (board[N - d % N][j] > 0 && board[N - d % N][j] < 4) {
					int r = N - d % N;
					int c = j;

					bool find = false;

					for (int t = 0; t < M; ++t) {
						for (int p = 0; p < team[t].size(); ++p) {
							if (team[t][p].first == r && team[t][p].second == c) {
								score += pow(p + 1, 2);
								isReverse[t] = !isReverse[t];
								reverse(team[t].begin(), team[t].end());
								find = true;
								break;
							}
						}

						if (find)
							break;
					}
				}
				if (find)
					break;
			}
		}
		else {
			for (int j = 0; j < N; ++j) {
				if (board[j][N - d % N] > 0 && board[j][N - d % N] < 4) {
					int r = j;
					int c = N - ( d % N );

					bool find = false;

					for (int t = 0; t < M; ++t) {
						for (int p = 0; p < team[t].size(); ++p) {
							if (team[t][p].first == r && team[t][p].second == c) {
								score += pow(p + 1, 2);
								isReverse[t] = !isReverse[t];
								reverse(team[t].begin(), team[t].end());
								find = true;
								break;
							}
						}

						if (find)
							break;
					}
				}
				if (find)
					break;
			}
		}

		cout << score << endl;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout<< board[i][j]<< " ";
			}
			cout << endl;
		}
		cout << endl;

	}

	cout << score << endl;

	return 0;
}