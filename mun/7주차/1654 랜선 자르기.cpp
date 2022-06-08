// https://www.acmicpc.net/problem/1654

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

// 변수들 크기를 int -> long long
// => 랜선의 길이가 INT_MAX이므로 오버플로우 방지 필요
int main() {
	long long K, N;

	cin >> K >> N;

	vector<long long> arr(K);
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	// 이분탐색 활용
	long long left = 1, right = arr.back(), mid = (left + right)/2;
	long long ans = -1;
	
	while (left <= right) {
		mid = (left + right) / 2;
		long long count = 0;
		for (int i = 0; i < K; ++i) {
			count += (arr[i] / mid);
		}

		if (count < N) right = mid - 1;
		else {
			// N보다 크게 만드는 것도 답에 포함해야하므로 여기에서 ans 갱신 진행
			ans = max(ans, mid);
			left = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}