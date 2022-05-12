// https://www.acmicpc.net/problem/19238

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, gas;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int> > map;

class guest {
public:
	int x1, y1, x2, y2;
	bool isArrive = false;

	guest() {}
	guest(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
};

// 최단 거리 탐색
int shortestDistance(int x1, int y1, int x2, int y2) {
	queue<pair<int, int> > q;
	vector<vector<int> > temp(N + 1, vector<int>(N + 1, -1));
	q.push(make_pair(x1, y1));
	temp[x1][y1] = 0;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (now.first == x2 && now.second == y2)
			break;

		for (int i = 0; i < 4; ++i) {
			int nX = now.first + dx[i];
			int nY = now.second + dy[i];

			if (nX > 0 && nX <= N && nY > 0 && nY <= N && map[nX][nY] == 0) {
				if (temp[nX][nY] == -1) {
					q.push(make_pair(nX, nY));
					temp[nX][nY] = temp[now.first][now.second] + 1;
				}
			}
		}
	}

	return temp[x2][y2];
}

int simulation(vector<guest>& guests, pair<int, int>& taxi) {
	vector<int> dis(M, -1);

	// 1. 운전자와 가장 거리가 짧은 손님 탐색
	int next = -1;
	for (int i = 0; i < M; ++i) {
		if (!guests[i].isArrive) {
			dis[i] = shortestDistance(taxi.first, taxi.second, guests[i].x1, guests[i].y1);

			if (dis[i] == -1)
				continue;

			if (next == -1)
				next = i;
			else if (dis[next] > dis[i])
				next = i;
			else if (dis[next] == dis[i]) {
				// 같은 경우 행 번호가 더 작은 승객을
				if (guests[next].x1 > guests[i].x1)
					next = i;
				// 행 번호도 같은 경우 열 번호가 더 작은 승객으로 결정
				else if (guests[next].x1 == guests[i].x1 && guests[next].y1 > guests[i].y1)
					next = i;
			}
		}
	}

	// 모두 갈 수 없는 경우
	if (next == -1)
		return -1;

	// 2. 택시 -> 손님
	gas -= dis[next];
	guests[next].isArrive = true;

	// 3. 도착지점까지 드는 연료
	int useGas = shortestDistance(guests[next].x1, guests[next].y1, guests[next].x2, guests[next].y2);

	// 연료가 도착지점 전에 바닥난 경우 or 도착지로 못 가는 경우
	if (useGas > gas || useGas == -1) {
		return -1;
	}
	// 도착한 경우
	else {
		gas += useGas;
		taxi.first = guests[next].x2;
		taxi.second = guests[next].y2;
		return gas;
	}

}

int main() {

	cin >> N >> M >> gas;

	map.resize(N + 1, vector<int>(N + 1));
	vector<guest> guests;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}

	pair<int, int> taxi;
	cin >> taxi.first >> taxi.second;

	int x1, y1, x2, y2;
	for (int i = 0; i < M; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		guests.push_back(guest(x1, y1, x2, y2));
	}

	int result = 0;
	for (int i = 0; i < M; ++i) {
		result = simulation(guests, taxi);

		if (result == -1) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << result << endl;

	return 0;
}