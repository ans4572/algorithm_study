// https://www.acmicpc.net/problem/13549

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

const int MAX = 100001;

int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	// deque 활용
	deque<int> dq;
	dq.push_back(N);
	arr[N] = 1;

	while (!dq.empty()) {
		int x = dq.front();
		dq.pop_front();

		if (x == K)
			break;

		// 순간이동
		if (x * 2 < MAX && !arr[x * 2]) {
			arr[x * 2] = arr[x];
			dq.push_front(x * 2);
		}
		
		// 좌우 이동
		if (x > 0 && !arr[x - 1]) {
			arr[x - 1] = arr[x] + 1;
			dq.push_back(x - 1);
		}
		if (x + 1 < MAX && !arr[x + 1]) {
			arr[x + 1] = arr[x] + 1;
			dq.push_back(x + 1);
		}
	}

	cout << arr[K] - 1 << endl;

	return 0;
}