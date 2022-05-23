// https://www.acmicpc.net/problem/1339

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<string> arr(N);
	vector<int> alphabet(26, 0);
	
	// �� ���帶�� �����ϴ� ���ĺ��� �ڸ����� ���� �����ش�.
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		int t = 1;
		for (int j = arr[i].length() - 1; j >= 0; --j) {
			alphabet[arr[i][j] - 'A'] += t;
			t *= 10;
		}
	}

	// �������� ����
	sort(alphabet.rbegin(), alphabet.rend());
	
	int ans = 0;
	int idx = 0, n = 9;
	while (alphabet[idx] > 0) {
		ans += alphabet[idx++] * n;
		n--;
	}

	cout << ans << endl;

	return 0;
}
