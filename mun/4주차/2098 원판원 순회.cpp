// https://www.acmicpc.net/problem/2098

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

const int INF = 16000001;

int N;
int city[16][16];
int dp[16][1 << 16];   //비트마스크를 활용해서 다이나믹 배열 생성, dp[i][j] => i: 현재 도시, j: 방문한 도시들 표현 비트

int DFS(int nowCity, int visited) {
	//모든 방문을 다 한 경우 => 11...11
	if (visited == (1 << N) - 1) {
		//현재 도시와 0번째 도시간의 연결점이 없는 경우
		if (city[nowCity][0] == 0)
			return INF;
		else
			return city[nowCity][0];
	}

	if (dp[nowCity][visited] != 0)
		return dp[nowCity][visited];

	dp[nowCity][visited] = INF;

	for (int i = 0; i < N; ++i) {
		//연결 안되어있는 경우
		if (city[nowCity][i] == 0)
			continue;
		//이미 방문한 곳인 경우
		if ((visited & (1 << i)) > 0)
			continue;

		//점화식
		dp[nowCity][visited] = min(dp[nowCity][visited], city[nowCity][i] + DFS(i, visited | (1 << i)));
	}

	return dp[nowCity][visited];
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> city[i][j];
		}
	}

	cout << DFS(0, 1) << endl;

	return 0;
}