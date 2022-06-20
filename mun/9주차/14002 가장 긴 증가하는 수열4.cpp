// https://www.acmicpc.net/problem/14002

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	// 순회하면서 각 인덱스마다 수열 개수 저장할 배열
	// 처음에는 각 arr마다 1로 두고 진행
	// 이전 값들을 역으로 가면서 조건에 따라 값 갱신
	vector<int> counts(N, 1);

	int maxCount = 1;
	int maxIdx = 0;
	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (arr[i] > arr[j]) {
				counts[i] = max(counts[i], counts[j] + 1);
			}
			
			if (maxCount < counts[i]) {
				maxCount = counts[i];
				maxIdx = i;
			}
		}
	}

	vector<int> ans;
	int val = arr[maxIdx];
	int count = maxCount - 1;
	ans.push_back(val);

	for (int i = maxIdx - 1; i >= 0; --i) {
		// 값은 더 작으면서 개수는 똑같은 인덱스 찾기
		if (val > arr[i] && counts[i] == count) {
			ans.push_back(arr[i]);
			count--;
			val = arr[i];
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int a : ans)
		cout << a << " ";

	return 0;
}