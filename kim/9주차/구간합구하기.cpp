#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
long long arr[1000002];
vector<long long> tree;

long long getSum(int start, int end, int node, int from, int to) {
	if (from > end || to < start) return 0;	// 범위 밖
	if (from <= start && to >= end) return tree[node];	//구간합이 모두 범위 안에 있는경우
	int mid = (start + end) / 2;	//그렇지 않다면 두 부분으로 나눠 합을 구한다.
	return getSum(start, mid, node * 2, from, to) + getSum(mid + 1, end, node * 2 + 1, from, to);
}

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start]; //트리끝에 도달한 경우 arr 삽입.

	int mid = (start + end) / 2;
	//트리 끝이 아닌경우는 좌측과 우측노드의 합을 넣어준다. (구간합)
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int what, long long val) {
	if (what < start || what >end) return;	//범위밖인경우
	tree[node] += val;
	if (start == end) return;

	int mid = (start + end) / 2;

	update(start, mid, node * 2, what, val);
	update(mid + 1, end, node * 2 + 1, what, val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;

	int height = ceil(log2(n));
	int treeSize = 1 << (height + 1);
	tree.assign(treeSize, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	init(0, n - 1, 1);

	for (int i = 0; i < m + k; i++) {
		int a, b; long long c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(0, n - 1, 1, b - 1, c-arr[b-1]);
			arr[b-1] = c;
		}
		else {
			cout << getSum(0, n - 1, 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}
