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
	// K�� 1�� ���� ������ ���
	if (K == 1) 
		return abs(a - b);
	
	long long dis = 0;

	// ��� ������ ���� a�� �� ���� ������ ����
	if (a > b)
		swap(a, b);

	// ���� ���� �۾�
	long long aDepth = getDepth(a);
	long long bDepth = getDepth(b);

	if (aDepth != bDepth) {
		for (int i = bDepth; i > aDepth; --i) {
			b = (b - 1) / K;
			dis++;
		}
	}

	// ���� �θ� ã�������� ����
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

		// 0���� �����ϱ� ���� 1�� ���� ����
		cout << getDistance(a - 1, b - 1) << "\n";
	}

	return 0;
}