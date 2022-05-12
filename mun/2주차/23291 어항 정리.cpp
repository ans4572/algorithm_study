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
int map[maxN][maxN];      // �⺻ ��
int newMap[maxN][maxN];   // ��ȯ�� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

// 1. ����� ä���
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

	// �ּ� ����� ���� 1�� ����
	for (int i = 0; i < minIndex.size(); ++i) {
		map[0][minIndex[i]]++;
	}
}

// 2. ���� �ױ�
void stackbowl() {
	int h = 1, w = 1, s = 1;  // ����, �ʺ�, ���� �ε���

	int idx = 0;
	while (true) {
		// ���� ����� ����
		if (s + h - 1 >=N )
			break;

		// 90�� ȸ���ϸ鼭 ���̱�
		for (int r = 0; r < h; ++r) {
			for (int c = s - w; c < s; c++) {
				map[s - c][s + r] = map[r][c];
				map[r][c] = 0;
			}
		}
		s += h;  // �ε��� �ű��

		// �ѹ��� ������ ���鼭 h or w ����
		idx % 2 == 0 ? h++ : w++;

		idx++;
	}
}

// 3. ����� �̵�
void movefish() {
	memset(newMap, 0, sizeof(newMap));

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (map[x][y] > 0) {
				newMap[x][y] += map[x][y];

				// 4���� Ȯ���Ͽ� �߰� ����
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

// 4. �ٽ� �Ϸķ� ���
void linearbowl() {
	int x;
	int idx = 0;
	memset(newMap, 0, sizeof(newMap));

	// ���� ���� x ��ġ ã��
	for (x = N - 1; x >= 0; --x) {
		if (map[0][x] == 0) {
			x++;
			break;
		}
	}

	// 0��° �ٿ� �߰��ϸ鼭 ����
	for (; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (map[y][x] == 0) break;
			newMap[0][idx++] = map[y][x];
		}
	}

	memcpy(map, newMap, sizeof(map));
}

// 5. ���� ����
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

// 6. Ȯ��
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