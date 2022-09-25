// https://school.programmers.co.kr/learn/courses/30/lessons/81302

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

int dw[4] = { 0,1,0,-1 };
int dh[4] = { 1,0,-1,0 };
bool visit[5][5];

bool BFS(int h, int w, vector<string> place) {
	memset(visit, false, sizeof(visit));
	queue<pair<pair<int, int>, int>> q; // {{h, w}, 거리}
	q.push({ {h,w},0 });
	visit[h][w] = true;

	while (!q.empty()) {
		int hh = q.front().first.first;
		int ww = q.front().first.second;
		int count = q.front().second;
		q.pop();

		// 이미 거리가 2라면 더 탐색 X
		if (count == 2)
			continue;

		for (int i = 0; i < 4; ++i) {
			int nh = hh + dh[i];
			int nw = ww + dw[i];
			if (nh >= 0 && nh < 5 && nw >= 0 && nw < 5) {
				if (visit[nh][nw] == false) {
					// 빈 테이블인 경우
					if (place[nh][nw] == 'O') {
						visit[nh][nw] = true;
						q.push({ {nh,nw},count + 1 });
					}
					// 사람인 경우
					if (place[nh][nw] == 'P') {
						return false;
					}
				}
			}
		}
	}

	return true;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < places.size(); ++i) {
		vector<string> place = places[i];
		bool isOk = true;

		for (int h = 0; h < place.size(); ++h) {
			for (int w = 0; w < place[h].size(); ++w) {
				// 사람인 경우 BFS 진행
				if (place[h][w] == 'P') {
					if (BFS(h, w, place) == false) {
						isOk = false;
					}
				}
			}
		}

		if (isOk) answer.push_back(1);
		else answer.push_back(0);
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> answer = solution({
		{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
		{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
		{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
		{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
		{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
		});

	for (int a : answer) {
		cout << a << endl;
	}

	return 0;
}