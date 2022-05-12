// https://www.acmicpc.net/problem/16236

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int N;
int map[21][21];
int visit[21][21];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int sharkSize = 2, sharkExp = 0;
int ans = 0;

class Location {
public:
	int y, x;

	Location() {
		x = y = 0;
	}
	Location(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

bool inMap(int y, int x) {
	return y >= 0 && y < N&& x >= 0 && x < N;
}

//먹을 수 있는 물고기를 탐색하여 위치 반환
Location eatLoc(Location s) {
	memset(visit, -1, sizeof(visit));

	queue<Location> q;
	vector<Location> candidate;    //가장 가까운 먹을 수 있는 물고기 후보 
	int minDis = 10000;           //최소 거리
	q.push(s);
	visit[s.y][s.x] = 0;
	
	// BFS
	while (!q.empty()) {
		Location loc = q.front();
		q.pop();

		if (minDis < visit[loc.y][loc.x]) continue;

		if (map[loc.y][loc.x] > 0 && map[loc.y][loc.x] < sharkSize && minDis >= visit[loc.y][loc.x]) {
			candidate.push_back(Location(loc.y, loc.x));
			minDis = visit[loc.y][loc.x];
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			int nextY = loc.y + dy[i];
			int nextX = loc.x + dx[i];

			if (inMap(nextY, nextX) && visit[nextY][nextX] == -1 && map[nextY][nextX] <= sharkSize) {
				visit[nextY][nextX] = visit[loc.y][loc.x] + 1;
				q.push(Location(nextY, nextX));
			}
		}
	}

	//만약 더 이상 먹을 수 있는 물고기가 없는 경우
	if (candidate.size() == 0) {
		return Location(-1, -1);
	}
	else {
		int moveY = candidate[0].y;
		int moveX = candidate[0].x;
		for (int i = 1; i < candidate.size(); ++i) {
			//더 위에 있는 경우
			if (moveY > candidate[i].y) {
				moveY = candidate[i].y;
				moveX = candidate[i].x;
			}
			//같은 y값을 가지면서 더 왼쪽에 있는 경우
			else if (moveY == candidate[i].y && moveX > candidate[i].x) {
				moveY = candidate[i].y;
				moveX = candidate[i].x;
			}
		}

		ans += visit[moveY][moveX];         //이동 거리 추가
		sharkExp++;                         //경험치 증가
		if (sharkExp == sharkSize) {        //만약 경험치가 크기와 같아진 경우
			sharkExp = 0;
			sharkSize++;
		}
		map[moveY][moveX] = 0;          //먹은 물고기의 공간은 0으로 변환
		map[s.y][s.x] = 0;              //기존의 상어 위치는 0으로 변환
		return Location(moveY, moveX);
	}
}

int main() {
	cin >> N;

	Location shark;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.y = i;
				shark.x = j;
			}
		}
	}

	while (shark.y != -1) {
		shark = eatLoc(shark);
	}

	cout << ans << endl;

	return 0;
}