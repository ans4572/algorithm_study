// https://www.acmicpc.net/problem/23291

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

const int maxN = 104;
int N, K;
int map[maxN][maxN];      // 기본 맵
int newMap[maxN][maxN];   // 전환할 맵
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// 1. 물고기 채우기
void addfish() {
	vector<int> minIndex;
	int minValue = INT_MAX;
	for (int i = 0; i < N; ++i) {
		if (minValue > map[0][i]) {
			minValue = map[0][i];
			minIndex.clear();
			minIndex.push_back(i);
		}
		else if (minValue == map[0][i]) {
			minIndex.push_back(i);
		}
	}

	// 최소 물고기 어항 1씩 증가
	for (int i = 0; i < minIndex.size(); ++i) {
		map[0][minIndex[i]]++;
	}
}

// 2. 어항 쌓기
void stackbowl() {
	int h = 1, w = 1, s = 1;  // 높이, 너비, 시작 인덱스

	int idx = 0;
	while (true) {
		// 범위 벗어나면 종료
		if (s + h - 1 >=N )
			break;

		// 90도 회전하면서 붙이기
		for (int r = 0; r < h; ++r) {
			for (int c = s - w; c < s; c++) {
				map[s - c][s + r] = map[r][c];
				map[r][c] = 0;
			}
		}
		s += h;  // 인덱스 옮기기

		// 한번씩 번갈아 가면서 h or w 증가
		idx % 2 == 0 ? h++ : w++;

		idx++;
	}
}

// 3. 물고기 이동
void movefish() {
	memset(newMap, 0, sizeof(newMap));

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (map[x][y] > 0) {
				newMap[x][y] += map[x][y];

				// 4방향 확인하여 추가 진행
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d];
					int ny = y + dy[d];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] > 0) {
						if (map[x][y] > map[nx][ny]) {
							int diff = (map[x][y] - map[nx][ny]) / 5;
							newMap[x][y] -= diff;
							newMap[nx][ny] += diff;
						}
					}
				}
			}
		}
	}

	memcpy(map, newMap, sizeof(map));
}

// 4. 다시 일렬로 펴기
void linearbowl() {
	int x;
	int idx = 0;
	memset(newMap, 0, sizeof(newMap));

	// 가장 왼쪽 x 위치 찾기
	for (x = N - 1; x >= 0; --x) {
		if (map[0][x] == 0) {
			x++;
			break;
		}
	}

	// 0번째 줄에 추가하면서 진행
	for (; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (map[y][x] == 0) break;
			newMap[0][idx++] = map[y][x];
		}
	}

	memcpy(map, newMap, sizeof(map));
}

// 5. 어항 접기
void foldbowl() {
	for (int i = 0; i < N / 4; i++) {
		map[1][N - 1 - i] = map[0][i];
		map[0][i] = 0;
	}

	for (int i = 0; i < N / 4; i++) {
		map[2][(N / 4) * 3 + i] = map[0][N / 4 + i];
		map[0][N / 4 + i] = 0;
	}

	for (int i = 0; i < N / 4; i++) {
		map[3][N - 1 - i] = map[0][(N / 4) * 2 + i];
		map[0][(N / 4) * 2 + i] = 0;
	}
}

// 6. 확인
bool check() {
	int minNum = INT_MAX;
	int maxNum = -1;
	for (int i = 0; i < N; i++) {
		minNum = min(minNum, map[0][i]);
		maxNum = max(maxNum, map[0][i]);
	}
	if (maxNum - minNum <= K) return true;
	else return false;
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> map[0][i];
	}

	int count = 0;
	while (true) {
		count++;

		addfish();

		stackbowl();
		movefish();
		linearbowl();

		foldbowl();
		movefish();
		linearbowl();

		if (check())
			break;
	}

	cout << count << endl;

	return 0;
}