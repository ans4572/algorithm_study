// https://www.acmicpc.net/problem/2933

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

int R, C;
char board[101][101];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void destroy(int h, bool isLeft) {
	if (isLeft) {
		for (int i = 0; i < C; ++i) {
			if (board[R - h][i] == 'x') {
				board[R - h][i] = '.';
				return;
			}
		}
	}
	else {
		for (int i = C - 1; i >= 0; --i) {
			if (board[R - h][i] == 'x') {
				board[R - h][i] = '.';
				return;
			}
		}
	}

	return;
}

void print() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}

	return;
}


// �̳׶� ���� �� ������ 
void rebuild() {
	bool visit[101][101] = { 0 };

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			// 1. Ŭ������ ã��
			if (board[r][c] == 'x' && !visit[r][c]) {
				vector<pair<int, int> > cluster;  // Ŭ������ ���� �迭
				cluster.push_back(make_pair(r, c));

				queue<pair<int, int>> q;
				q.push(make_pair(r, c));

				while (!q.empty()) {
					pair<int, int> now = q.front();
					q.pop();

					for (int d = 0; d < 4; ++d) {
						int nr = now.first + dr[d];
						int nc = now.second + dc[d];
						if (nr >= 0 && nr < R && nc >= 0 && nc < C && board[nr][nc] == 'x' && !visit[nr][nc]) {
							cluster.push_back(make_pair(nr, nc));
							visit[nr][nc] = true;
							q.push(make_pair(nr, nc));
						}
					}
				}

				// 2. Ŭ������ �� �Ʒ� �κ� ã��
				vector<pair<int, int> > bottom;
				bottom.push_back(make_pair(r, c));
				for (int i = 1; i < cluster.size(); ++i) {
					if (bottom[0].first < cluster[i].first) {
						bottom.clear();
						bottom.push_back(cluster[i]);
					}
					else if(bottom[0].first == cluster[i].first)
						bottom.push_back(cluster[i]);
				}
				
				// �ٴ��� ���
				if (bottom[0].first == R - 1)
					continue;

				// 3. �ٴ��� �ƴϹǷ� ������������ �Ǵ�. ������ �̵���ų �ּ� �Ÿ� ã��
				int minLength = R - 1 - bottom[0].first;  // �ʱⰪ = �ִ� ������ �ٴڱ����� ����
				for (int i = 0; i < bottom.size(); ++i) {
					for (int j = bottom[i].first + 1; j < R; ++j) {
						if (board[j][bottom[i].second] == 'x')
							minLength = min(minLength, j - bottom[i].first - 1);
					}
				}

				// 4. Ŭ������ �غ��� �̵�
				sort(cluster.rbegin(), cluster.rend());

				for (int i = 0; i < cluster.size(); ++i) {
					board[cluster[i].first + minLength][cluster[i].second] = 'x';
					visit[cluster[i].first + minLength][cluster[i].second] = true;
					board[cluster[i].first][cluster[i].second] = '.';
				}

			}
			visit[r][c] = true;
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin>>board[i][j];
		}
	}

	int N;
	cin >> N;
	vector<int> high(N);
	bool isLeft = true;

	for (int i = 0; i < N; ++i) 
		cin >> high[i];
	
	for (int i = 0; i < N; ++i) {
		destroy(high[i], isLeft);
		rebuild();
		isLeft = !isLeft;
	}

	print();

	return 0;
}