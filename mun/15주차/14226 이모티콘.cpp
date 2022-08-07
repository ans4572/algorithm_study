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

	queue<tuple<int, int, int>> q; // first: 현재 화면 개수, second: 현재 클립보드 개수, third: 걸린 시간
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

		// 화면 -> 클립 저장
		if (!visit[screen][screen]) {
			visit[screen][screen] = true;
			q.push({ screen, screen, time + 1 });
		}
		// 클립 -> 화면 복사
		// 단 비어있으면 붙여넣기 불가능
		if (screen + clip <= 1000 && !visit[screen + clip][clip] && clip > 0) {
			visit[screen + clip][clip] = true;
			q.push({ screen + clip, clip, time + 1 });
		}
		// 삭제
		if (!visit[screen - 1][clip] && screen > 1) {
			visit[screen - 1][clip] = true;
			q.push({ screen - 1, clip, time + 1 });
		}
	}

	cout << ans << endl;

	return 0;
}