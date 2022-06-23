// https://www.acmicpc.net/problem/2042

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

long long* seg;
long long arr[10000001];

// 세그먼트 트리 초기화 함수
// node: 시작 노드, s: start, e: end
long long init(int node, int s, int e) {
	if (s == e) return seg[node] = arr[s]; 
	int mid = (s + e) / 2;

	// 왼쪽 자식과 오른쪽 자식 트리를 만들고 합을 저장
	return seg[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}

// 구간합 구하는 함수
// s ~ e: 현재 구간, l ~ r : 찾아야하는 구간
long long prefixSum(int node, int s, int e, int l, int r) {
	// 구간에 겹치지 않는 경우
	if (e < l || r < s) return 0;

	// 구간에 완전히 겹치는 경우
	if (l <= s && e <= r) return seg[node];

	// 부분적으로 겹치는 경우
	int mid = (s + e) / 2;
	return prefixSum(2 * node, s, mid, l, r) + prefixSum(2 * node + 1, mid + 1, e, l, r);
}

// 숫자 변경 함수
// s ~ e: 현재 구간, idx: 찾는 수의 인덱스, diff: 차이
void change(int node, int s, int e, int idx, long long diff) {
	// 구간에 겹치지 않는 경우
	if (e < idx || idx < s) return;

	// 트리 갱신 진행
	seg[node] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		change(2 * node, s, mid, idx, diff);
		change(2 * node + 1, mid + 1, e, idx, diff);
	}
}

int main() {
	int N, M, K;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) 
		cin >> arr[i];

	// 세그먼트 트리의 사이즈 = 2 ^ (트리의 높이 + 1)
	int h = ceil(log2(N));
	seg = new long long[1 << (h + 1)];

	// 세그먼트 트리 생성
	init(1, 1, N);

	long long a, b, c;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;

		if (a == 1) {
			long long diff = c - arr[b];
			arr[b] = c;
			change(1, 1, N, b, diff);
		}
		else {
			cout << prefixSum(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}