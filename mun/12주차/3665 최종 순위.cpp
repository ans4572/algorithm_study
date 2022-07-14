// https://www.acmicpc.net/problem/3665

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

bool edge[501][501];    // ���� ���� ����
int lastYearRank[501];  // �۳� ����
int result[501];        
int inDegree[501];      // ���� ���� �迭

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; ++tc) {
		int N, M;
		cin >> N;

		memset(edge, false, sizeof(edge));

		for (int i = 1; i <= N; ++i) {
			cin >> lastYearRank[i];
			result[i] = 0;
			inDegree[i] = 0;
		}
		
		for (int i = 1; i <= N; ++i) {
			int s = lastYearRank[i];
			for (int j = i + 1; j <= N; ++j) {
				edge[s][lastYearRank[j]] = true;
				inDegree[lastYearRank[j]]++;
			}
		}

		cin >> M;
		
		// ���� ���� ����
		for (int i = 0; i < M; i++) {
			int from, to;
			cin >> from >> to;

			if (edge[from][to]) {
				edge[from][to] = false;
				edge[to][from] = true;
				inDegree[to]--;
				inDegree[from]++;
			}
			else {
				edge[to][from] = false;
				edge[from][to] = true;
				inDegree[from]--;
				inDegree[to]++;
			}
		}

		// �������� ������ ť�� Ȱ��
		// ���� ������ 0�� ��带 ����
		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (inDegree[i] == 0)
				q.push(i);
		}

		bool isPossible = true;
		// ���� ������ 0�� ���� �ϳ��� �߰��Ͽ� �˻��ϴ� �������� ����
		// 1����� �����Ͽ� ����� ����
		for (int i = 0; i < N; ++i) {
			// ť�� ������� = �� �̻� ������ ���� �� ����
			if (q.empty()) {
				cout << "IMPOSSIBLE" << endl;
				isPossible = false;
				break;
			}
			// ť�� ũ�Ⱑ 1���� ū ��� = Ȯ���� ������ ã�� �� ����
			if (q.size() > 1) {
				cout << "?" << endl;
				isPossible = false;
				break;
			}
			
			int now = q.front();
			result[i + 1] = now;
			q.pop();
			inDegree[now]--;

			for (int j = 1; j <= N; ++j) {
				if (edge[now][j]) inDegree[j]--;
				if (inDegree[j] == 0) q.push(j);
			}
		}

		if (isPossible) {
			for (int i = 1; i <= N; ++i) {
				cout << result[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
