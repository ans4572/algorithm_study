// https://www.acmicpc.net/problem/14226

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>
#include <tuple>

using namespace std;

bool visit[1001][1001];

int main() {

	int S;
	cin >> S;

	queue<tuple<int, int, int>> q; // first: ���� ȭ�� ����, second: ���� Ŭ������ ����, third: �ɸ� �ð�
	q.push({ 1, 0, 0 });
	visit[1][0] = true;

	int ans = 0;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		int screen = get<0>(now);
		int clip = get<1>(now);
		int time = get<2>(now);

		if (screen > 1000 || clip > 1000)
			continue;

		if (screen == S) {
			ans = time;
			break;
		}

		// ȭ�� -> Ŭ�� ����
		if (!visit[screen][screen]) {
			visit[screen][screen] = true;
			q.push({ screen, screen, time + 1 });
		}
		// Ŭ�� -> ȭ�� ����
		// �� ��������� �ٿ��ֱ� �Ұ���
		if (screen + clip <= 1000 && !visit[screen + clip][clip] && clip > 0) {
			visit[screen + clip][clip] = true;
			q.push({ screen + clip, clip, time + 1 });
		}
		// ����
		if (!visit[screen - 1][clip] && screen > 1) {
			visit[screen - 1][clip] = true;
			q.push({ screen - 1, clip, time + 1 });
		}
	}

	cout << ans << endl;

	return 0;
}