// https://www.acmicpc.net/problem/17298

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

int ans[1000001];
int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	stack<int> s;

	for (int i = N - 1; i >= 0; --i) {
		// ���� ���� ������ top�� ���� ������ ������� ��� �����ϱ�
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
		
		if (s.empty())
			ans[i] = -1;
		// ������ ������� ������ top�� �������� ����
		else
			ans[i] = s.top();

		s.push(arr[i]);
	}

	for (int i = 0; i < N; ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}