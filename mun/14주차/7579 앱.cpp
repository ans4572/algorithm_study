// https://www.acmicpc.net/problem/7579

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

int dy[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> memory(N);
	vector<int> cost(N);

	for (int i = 0; i < N; ++i)
		cin >> memory[i];

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> cost[i];
		sum += cost[i];
	}

	//배낭문제 알고리즘 활용
	for (int i = 0; i < N; ++i) {
		for (int j = sum; j >= cost[i]; --j) {
			dy[j] = max(dy[j], dy[j - cost[i]] + memory[i]);
		}
	}

	int ans;
	for (int i = 0; i <= 10000; ++i) {
		if (dy[i] >= M) {
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}