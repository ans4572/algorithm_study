// https://www.codetree.ai/frequent-problems/cube-rounding/description

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

int N, M;
int board[9][9];
vector<pair<int, int>> vec;  // ���� ��ǥ ���� �迭
bool visit[9][9];            // �湮 ����
int ans = 100;
int dn[4] = { 1, -1, 0, 0 };
int dm[4] = { 0, 0, 1, -1 };

// ������ ���� �̵� ����
vector<vector<int>> piece = {
	{},
	{1, 0, 0, 0},
	{0, 1, 0, 1},
	{1, 1, 0, 0},
	{1, 1, 0, 1},
	{1, 1, 1, 1}
};

// �� �������� �� �̵���Ű�� �Լ�
// (n,m): ��ǥ / d: ����
void move(int n, int m, int d) {
	visit[n][m] = true;

	int nn = n + dn[d];
	int mm = m + dm[d];

	while (true) {
		// ���� ��� ���
		if (nn < 0 || nn >= N || mm > 0 || mm >= M)
			break;

		visit[nn][mm] = true;

		// ���� ü�� ���� ���
		if (board[nn][mm] == 6) 
			break;
		
		nn += dn[d];
		mm += dm[d];
	}

	return;
}

void chess(int idx, vector<int> &dir) {
	if (idx == vec.size()) {

		memset(visit, false, sizeof(visit));

		for (int i = 0; i < vec.size(); ++i) {
			int n = vec[i].first;
			int m = vec[i].second;

			// ���� �� ���⿡ ���� �̵��� �� �ִ� ���� ���� ���ϸ鼭 �̵�
			for (int d = 0; d < 4; ++d) {
				go[d + dir] = piece[board[n][m]][(d + dir[i]) % 4];
			}

		}

		int count = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if(!visit[i][j]) count++;
			}
		}

		ans = min(ans, count);

		return;
	}
	else {
		// �� ������ 4�������� ���� 
		for (int i = 0; i < 4; ++i) {
			dir[idx] = i;
			chess(idx + 1, dir);
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];

			if (board[i][j] > 0 && board[i][j] != 6) 
				vec.push_back(make_pair(i,j));
		}
	}

	vector<int> dir(vec.size(), 0);

	chess(0, dir);

	cout << ans << endl;

	return 0;
}