// https://www.acmicpc.net/problem/11577

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

bool arr[100001];

int main() {

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int ans = 0;

	// K�� 1�� ��� = ������ ����
	if (K == 1) {
		for (int i = 0; i < N; ++i) {
			if (arr[i] == 1)
				ans++;
		}

		cout << ans << endl;
		return 0;
	}

	queue<int> q;
	for (int i = 0; i <= N - K; ++i) {
		// ť�� ���� ������ ¦���� ��� = ���� ����ġ ���ڸ� ����
		if (q.size() % 2 == 0)
		{
			// on�̶�� ����ġ�� �ѹ� �����Ƿ� ť�� push
			if (arr[i] == 1) {
				q.push(i + K - 1);
				ans++;
			}
			// off��� �� �̻� ���� X
		}
		// ť�� ���� ������ Ȧ���� ��� = ���� ����ġ�� �ݴ� ��Ȳ
		else
		{
			// ���� off = ���� on��Ȳ
			if (arr[i] == 0)
			{
				q.push(i + K - 1);
				ans++;
			}
		}

		// ���� �ε������� �Դٸ� pop ����
		if (!q.empty() && q.front() == i)
			q.pop();
	}

	// ���� �κ� ����
	for (int i = N - K + 1; i < N; ++i) {
		// ���� ť ���� ¦�� && ����ġ on / Ȧ�� && ����ġ off
		if ((q.size() % 2 == 0 && arr[i] == 1) || (q.size() % 2 == 1 && arr[i] == 0))
		{
			cout << "Insomnia" << endl;
			return 0;
		}

		// ���� �ε������� �Դٸ� pop ����
		if (q.front() == i)
			q.pop();
	}


	cout << ans << endl;

	return 0;
}