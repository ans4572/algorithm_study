// https://www.acmicpc.net/problem/1806

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	vector<int> vec(N);

	for (int i = 0; i < N; ++i)
		cin >> vec[i];

	int left = 0, right = 0, sum = vec[0];
	int ans = 100000;

	while (true) {
		if (ans == 1)
			break;

		if (sum >= S) {
			ans = min(ans, right - left + 1);
			sum -= vec[left];
			left++;
		}
		else {
			right++;
			sum += vec[right];
		}

		if (right == N - 1)
			break;
	}

	//남은 부분 확인
	while (left <= right && sum >= S) {
		ans = min(ans, right - left + 1);
		sum -= vec[left];
		left++;
	}

	if (ans == 100000)
		cout << 0 << endl;
	else
		cout << ans << endl;

	return 0;
}