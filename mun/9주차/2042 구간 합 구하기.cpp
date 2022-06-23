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

// ���׸�Ʈ Ʈ�� �ʱ�ȭ �Լ�
// node: ���� ���, s: start, e: end
long long init(int node, int s, int e) {
	if (s == e) return seg[node] = arr[s]; 
	int mid = (s + e) / 2;

	// ���� �ڽİ� ������ �ڽ� Ʈ���� ����� ���� ����
	return seg[node] = init(2 * node, s, mid) + init(2 * node + 1, mid + 1, e);
}

// ������ ���ϴ� �Լ�
// s ~ e: ���� ����, l ~ r : ã�ƾ��ϴ� ����
long long prefixSum(int node, int s, int e, int l, int r) {
	// ������ ��ġ�� �ʴ� ���
	if (e < l || r < s) return 0;

	// ������ ������ ��ġ�� ���
	if (l <= s && e <= r) return seg[node];

	// �κ������� ��ġ�� ���
	int mid = (s + e) / 2;
	return prefixSum(2 * node, s, mid, l, r) + prefixSum(2 * node + 1, mid + 1, e, l, r);
}

// ���� ���� �Լ�
// s ~ e: ���� ����, idx: ã�� ���� �ε���, diff: ����
void change(int node, int s, int e, int idx, long long diff) {
	// ������ ��ġ�� �ʴ� ���
	if (e < idx || idx < s) return;

	// Ʈ�� ���� ����
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

	// ���׸�Ʈ Ʈ���� ������ = 2 ^ (Ʈ���� ���� + 1)
	int h = ceil(log2(N));
	seg = new long long[1 << (h + 1)];

	// ���׸�Ʈ Ʈ�� ����
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