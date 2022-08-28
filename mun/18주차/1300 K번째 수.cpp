// https://www.acmicpc.net/problem/1300

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
#include <tuple>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	int left = 1, right = K, mid, ans;

	// 이분탐색 활용

	while (left <= right) {
		long long count = 0;
		mid = (left + right) / 2;

		for (int i = 1; i <= N; ++i) {
			count += min(mid / i, N);
		}

		if (count < K)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}