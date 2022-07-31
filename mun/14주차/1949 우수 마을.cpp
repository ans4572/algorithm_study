// https://www.acmicpc.net/problem/1949

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

vector<int> arr(10001);
vector<int> edge[10001];
bool visit[10001];
int dy[10001][2];  // dy[i][0]: i번째 마을은 일반, dy[i][1]: i번째 마을은 우수

void DFS(int now) {

	if (visit[now])
		return;
	
	visit[now] = true;
	dy[now][0] = 0;
	dy[now][1] = arr[now];

	// 연결된 마을 모두 확인
	for (int next : edge[now]) {
		if (visit[next])
			continue;

		DFS(next);
		dy[now][0] += max(dy[next][0], dy[next][1]);
		dy[now][1] += dy[next][0];
		
	}
}

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	DFS(1);

	cout << max(dy[1][0], dy[1][1]) << endl;

	return 0;
}