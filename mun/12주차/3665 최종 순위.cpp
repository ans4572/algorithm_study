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

bool edge[501][501];    // 연결 여부 저장
int lastYearRank[501];  // 작년 순위
int result[501];        
int inDegree[501];      // 진입 차수 배열

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
		
		// 방향 변경 진행
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

		// 위상정렬 구현을 큐로 활용
		// 진입 차수가 0인 노드를 넣음
		queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (inDegree[i] == 0)
				q.push(i);
		}

		bool isPossible = true;
		// 진입 차수가 0인 수를 하나씩 추가하여 검사하는 로직으로 진행
		// 1등부터 진행하여 결과에 저장
		for (int i = 0; i < N; ++i) {
			// 큐가 비어있음 = 더 이상 순위를 정할 수 없음
			if (q.empty()) {
				cout << "IMPOSSIBLE" << endl;
				isPossible = false;
				break;
			}
			// 큐의 크기가 1보다 큰 경우 = 확실한 순위를 찾을 수 없음
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
