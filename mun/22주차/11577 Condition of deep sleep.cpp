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

	// K가 1인 경우 = 무조건 성공
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
		// 큐에 남은 개수가 짝수인 경우 = 원래 스위치 제자리 유지
		if (q.size() % 2 == 0)
		{
			// on이라면 스위치를 한번 누르므로 큐에 push
			if (arr[i] == 1) {
				q.push(i + K - 1);
				ans++;
			}
			// off라면 더 이상 진행 X
		}
		// 큐에 남은 개수가 홀수인 경우 = 원래 스위치와 반대 상황
		else
		{
			// 원래 off = 현재 on상황
			if (arr[i] == 0)
			{
				q.push(i + K - 1);
				ans++;
			}
		}

		// 현재 인덱스까지 왔다면 pop 진행
		if (!q.empty() && q.front() == i)
			q.pop();
	}

	// 남은 부분 진행
	for (int i = N - K + 1; i < N; ++i) {
		// 남은 큐 개수 짝수 && 스위치 on / 홀수 && 스위치 off
		if ((q.size() % 2 == 0 && arr[i] == 1) || (q.size() % 2 == 1 && arr[i] == 0))
		{
			cout << "Insomnia" << endl;
			return 0;
		}

		// 현재 인덱스까지 왔다면 pop 진행
		if (q.front() == i)
			q.pop();
	}


	cout << ans << endl;

	return 0;
}