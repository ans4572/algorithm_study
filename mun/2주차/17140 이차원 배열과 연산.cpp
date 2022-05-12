// https://www.acmicpc.net/problem/17140

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int board[101][101];
int R, C;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

vector<int> rcSort(vector<int> vec) {

	// 1. 수 몇번 등장했는지 카운트, map 활용
	map<int, int> m;
	for (const int n : vec) {
		if (m.find(n) != m.end())
			m[n]++;
		else
			m[n] = 1;
	}

	// 2. 등장 횟수&커지는 수에 따른 정렬 진행
	vector<pair<int, int> > sortVec(m.begin(), m.end());
	sort(sortVec.begin(), sortVec.end(), cmp);
	
	// 3. 새로운 배열에 정렬된 결과를 넣고 반환
	vector<int> newVec;
	for (int i = 0; i < sortVec.size(); ++i) {
		// 0은 제외
		if (sortVec[i].first == 0)
			continue;
		newVec.push_back(sortVec[i].first);
		newVec.push_back(sortVec[i].second);
	}

	return newVec;
}

void cal() {

	vector<int> vec;
	// R 연산
	if (R >= C) {
		for (int i = 1; i <= R; ++i) {
			vec.clear();
			for (int j = 1; j <= C; ++j) {
				vec.push_back(board[i][j]);
			}
			vec = rcSort(vec);
			for (int j = 0; j < 100; ++j) {
				if (j < vec.size())
					board[i][j + 1] = vec[j];
				else 
					board[i][j + 1] = 0;
			}
			
			int size = vec.size();
			C = min(max(C, size), 100);
		}
	}
	// C 연산
	else {
		for (int i = 1; i <= C; ++i) {
			vec.clear();
			for (int j = 1; j <= R; ++j) {
				vec.push_back(board[j][i]);
			}
			vec = rcSort(vec);
			for (int j = 0; j < 100; ++j) {
				if (j < vec.size())
					board[j + 1][i] = vec[j];
				else 
					board[j + 1][i] = 0;
			}
			int size = vec.size();
			R = min(max(R, size), 100);
		}
	}
}

int main() {

	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> board[i][j];
		}
	}

	R = 3;
	C = 3;
	int time = 0;

	while (board[r][c] != k && time <= 100) {
		time++;
		cal();
	}

	if (time == 101)
		cout << -1 << endl;
	else
		cout << time;

	return 0;
}