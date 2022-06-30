// https://www.acmicpc.net/problem/2151

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int N;
char arr[51][51]{};
int visit[51][51][4];  // 각 위치마다 4개의 방향에 대한 방문 처리
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
const int INF = 10000000;

class state {
public:
	int x = 0, y = 0;   // 좌표
	int d = 0;          // 방향

	state() {}
	state(int y, int x, int d) {
		this->y = y;
		this->x = x;
		this->d = d;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	pair<int, int> door1 = { -1,-1 }, door2 = { -1,-1 };
	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = s[j];
			// 문들 저장
			if (arr[i][j] == '#') {
				if (door1.first == -1)
					door1 = { i,j };
				else
					door2 = { i,j };
			}
			// 방문 배열 최대값으로 초기화 진행
			visit[i][j][0] = visit[i][j][1] = visit[i][j][2] = visit[i][j][3] = INF;
		}
	}

	// BFS 활용
	queue<state> queue;
	for (int i = 0; i < 4; ++i) {
		queue.push(state(door1.first, door1.second, i));
		visit[door1.first][door1.second][i] = 0;
	}

	while (!queue.empty()) {
		state nowState = queue.front();
		queue.pop();

		int x = nowState.x;
		int y = nowState.y;
		int d = nowState.d;
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny < 0 || ny >= N && nx < 0 && nx >= N)
			continue;

		if (arr[ny][nx] == '*')
			continue;
		// 그대로 진행하는 경우
		else if (arr[ny][nx] == '.') {
			if (visit[ny][nx][d] > visit[y][x][d]) {
				visit[ny][nx][d] = visit[y][x][d];
				queue.push(state(ny, nx, d));
			}
		}
		else if (arr[ny][nx] == '!') {
			// 거울을 설치하지 않고 넘어가는 경우
			if (visit[ny][nx][d] > visit[y][x][d]) {
				visit[ny][nx][d] = visit[y][x][d];
				queue.push(state(ny, nx, d));
			}

			// 거울을 설치하는 경우 => 방향 변경
			if (d < 2) {
				if (visit[ny][nx][2] > visit[y][x][d] + 1) {
					visit[ny][nx][2] = visit[y][x][d] + 1;
					queue.push(state(ny, nx, 2));
				}
				if (visit[ny][nx][3] > visit[y][x][d] + 1) {
					visit[ny][nx][3] = visit[y][x][d] + 1;
					queue.push(state(ny, nx, 3));
				}
			}
			else {
				if (visit[ny][nx][0] > visit[y][x][d] + 1) {
					visit[ny][nx][0] = visit[y][x][d] + 1;
					queue.push(state(ny, nx, 0));
				}
				if (visit[ny][nx][1] > visit[y][x][d] + 1) {
					visit[ny][nx][1] = visit[y][x][d] + 1;
					queue.push(state(ny, nx, 1));
				}
			}
		}
		else if (arr[ny][nx] == '#') {
			visit[ny][nx][d] = min(visit[ny][nx][d], visit[y][x][d]);
		}
	}

	int ans = INF;
	for (int i = 0; i < 4; ++i) {
		ans = min(ans, visit[door2.first][door2.second][i]);
	}
	
	cout << ans << endl;

	return 0;
}
