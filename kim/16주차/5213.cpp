#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

pair<int,int> table[510][1020];	//타일 값, 타일 번호
int n, tileNum;
int visited[510][1020];
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int tile;
int path[510 * 1020];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	q.push({ 1,2 });
	visited[1][1] = 1;
	visited[1][2] = 1;

	path[1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (table[x][y].second == tileNum) {
			tile = table[x][y].second;
			return;
		}
		else tile = max(tile, table[x][y].second);	//  이동불가능한 경우 대비 큰타일 저장

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (visited[nx][ny] != 0) continue;	//방문함
			if (table[nx][ny].first == 0 || table[nx][ny].second == 0) continue;	//범위밖
		
			// 타일 번호 다르고, 값은 같아야 이동 가능
			if (table[x][y].second != table[nx][ny].second && table[x][y].first == table[nx][ny].first) {
				q.push({ nx,ny });
				visited[nx][ny] = visited[x][y] + 1;
				path[table[nx][ny].second] = table[x][y].second;

				// 이동할 다음 타일의 왼쪽 혹은 오른쪽 값도 적용시켜줘야 함.
				if (table[nx][ny - 1].second == table[nx][ny].second) {	
					q.push({ nx,ny - 1 });
					visited[nx][ny - 1] = visited[nx][ny];
				}
				else if (table[nx][ny + 1].second == table[nx][ny].second) {
					q.push({ nx,ny + 1 });
					visited[nx][ny + 1] = visited[nx][ny];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	// 데이터 입력
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {	//홀수
			for (int j = 1; j <= 2 * n; j++) {
				if (j % 2 == 1) tileNum++;
				int a; cin >> a;
				table[i][j].first = a;
				table[i][j].second = tileNum;
			}
		}
		else {				//짝수
			for (int j = 2; j <= 2 * n - 1; j++) {
				if (j % 2 == 0) tileNum++;
				int a; cin >> a;
				table[i][j].first = a;
				table[i][j].second = tileNum;
			}
		}
	}

	bfs();

	vector<int> res;
	int idx = tile;
	while (path[idx] != 0) {
		res.push_back(idx);
		idx = path[idx];
	}
	res.push_back(1);
	cout << res.size() << "\n";
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";

	return 0;
}
