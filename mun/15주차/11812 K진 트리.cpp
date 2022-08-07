// https://www.acmicpc.net/problem/11812

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

long long N, K, Q;

long long getDepth(long long x) {
	long long depth = 0;

	if (x != 0) {
		depth = 1;
		long long left = 1, right = K;

		while (!(left <= x && x <= right)) {
			depth++;
			left = left * K + 1;
			right = right * K + K;
		}
	}

	return depth;
}

long long getDistance(long long a, long long b) {
	// K가 1인 경우는 일자인 경우
	if (K == 1) 
		return abs(a - b);
	
	long long dis = 0;

	// 계산 통일을 위해 a를 더 작은 값으로 변경
	if (a > b)
		swap(a, b);

	// 깊이 통일 작업
	long long aDepth = getDepth(a);
	long long bDepth = getDepth(b);

	if (aDepth != bDepth) {
		for (int i = bDepth; i > aDepth; --i) {
			b = (b - 1) / K;
			dis++;
		}
	}

	// 동일 부모 찾을때까지 진행
	while (a != b) {
		a = (a - 1) / K;
		b = (b - 1) / K;
		dis += 2;
	}

	return dis;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;

	long long a, b;
	for (int i = 0; i < Q; ++i) {
		cin >> a >> b;

		// 0부터 시작하기 위해 1씩 빼서 진행
		cout << getDistance(a - 1, b - 1) << "\n";
	}

	return 0;
}