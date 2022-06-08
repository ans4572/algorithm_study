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

// ������ ũ�⸦ int -> long long
// => ������ ���̰� INT_MAX�̹Ƿ� �����÷ο� ���� �ʿ�
int main() {
	long long K, N;

	cin >> K >> N;

	vector<long long> arr(K);
	for (int i = 0; i < K; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	// �̺�Ž�� Ȱ��
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
			// N���� ũ�� ����� �͵� �信 �����ؾ��ϹǷ� ���⿡�� ans ���� ����
			ans = max(ans, mid);
			left = mid + 1;
		}
	}

	cout << ans << endl;

	return 0;
}