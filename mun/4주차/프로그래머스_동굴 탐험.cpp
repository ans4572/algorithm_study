// https://programmers.co.kr/learn/courses/30/lessons/67260
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#include<stack>

using namespace std;

const int maxN = 200001;

vector<int> edge[maxN];     // 양방향 그래프
vector<int> delay(maxN);    // 미룬 노드 저장
vector<int> before(maxN);   // 먼저 방문해야하는 노드 저장
vector<bool> visit(maxN);   

void DFS(int num) {
	// 이미 방문한 경우
	if (visit[num]) return;

	// num 이전에 방문해야 할 방을 아직 방문하지 않은 경우
	if (!visit[before[num]]) {
		delay[before[num]] = num;
		return;
	}

	visit[num] = true;
	DFS(delay[num]);

	for (int n : edge[num])
		DFS(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	for (auto iter : path) {
		edge[iter[0]].push_back(iter[1]);
		edge[iter[1]].push_back(iter[0]);
	}

	for (auto iter : order) {
		before[iter[1]] = iter[0];
	}

	// 0번 노드를 늦게 방문하는 경우
	if (before[0])
		return false;

	// 0번 방부터 DFS 시작
	visit[0] = true;
	for (int n : edge[0])
		DFS(n);

	// 모든 방을 탐색했는지 확인
	for (int i = 0; i < n; ++i) {
		if (!visit[i])
			return false;
	}

	return true;
}

int main() {

	string s;
	cin >> s;



	return 0;
}