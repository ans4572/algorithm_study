#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m;
int table[301][301];
bool visited[301][301];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

struct Info {
	int x;
	int y;
	int removeCnt;	//제거할 카운트 개수 (주위 바다 개수)
};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	vector<Info> info;	// 제거할 카운트 개수와 위치 저장.

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		int cnt = 0;	// 바다 카운트

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny]) continue;

			if (table[nx][ny] > 0) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}

			if (table[x][y] > 0 && table[nx][ny] == 0) cnt++;
		}

		if (cnt > 0)info.push_back({ x,y,cnt });
	}

	// 빙산 제거
	for (auto val : info) {
		table[val.x][val.y] -= val.removeCnt;
		if (table[val.x][val.y] < 0) table[val.x][val.y] = 0;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	
	int year = 0;
	while (true) {

		int iceCnt = 0;

		//초기화 및 빙산 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = false;
				if (table[i][j] == 0) iceCnt++;
			}
		}

		if (iceCnt == m*n) {		//빙산 다 녹으면 0 출력
			cout << 0;
			return 0;
		}

		int ice = 0;	//빙산 개수

		//바다 카운트
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && table[i][j] > 0) {
					ice++;
					bfs(i, j);
				}
			}
		}

		if (ice >= 2) {
			cout << year;
			return 0;
		}

		year++;
	}

	return 0;
}
