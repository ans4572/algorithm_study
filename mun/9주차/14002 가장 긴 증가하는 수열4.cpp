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

	// ��ȸ�ϸ鼭 �� �ε������� ���� ���� ������ �迭
	// ó������ �� arr���� 1�� �ΰ� ����
	// ���� ������ ������ ���鼭 ���ǿ� ���� �� ����
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
		// ���� �� �����鼭 ������ �Ȱ��� �ε��� ã��
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