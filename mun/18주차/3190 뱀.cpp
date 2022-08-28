//https://www.acmicpc.net/problem/3190

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

int N, K;
int board[101][101];   //board => 0: 빈칸, 1: 사과, 2: 뱀

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool inboard(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	// 사과 세팅
	int x, y;
	for (int i = 0; i < K; ++i) {
		cin >> y >> x;
		board[y][x] = 1;
	}

	int L, X;
	char C;
	vector<pair<int, char> > change;
	cin >> L;
	//변환 정보 세팅
	for (int i = 0; i < L; ++i) {
		cin >> X >> C;
		change.push_back(make_pair(X, C));
	}

	int nowY = 1, nowX = 1, changeIndex = 0, ans = 1, dicIndex = 0;
	queue<pair<int, int> > q;  //뱀의 몸이 맵에 존재하는 위치들 저장하는 큐
	q.push(make_pair(1, 1));
	board[1][1] = 2;

	while (inboard(nowX + dx[dicIndex], nowY + dy[dicIndex])) {
		nowX = nowX + dx[dicIndex];
		nowY = nowY + dy[dicIndex];

		//다음 칸이 빈칸인 경우
		if (board[nowY][nowX] == 0) {
			q.push(make_pair(nowY, nowX));
			board[nowY][nowX] = 2;
			board[q.front().first][q.front().second] = 0;
			q.pop();
		}
		//다음 칸이 사과인 경우
		else if (board[nowY][nowX] == 1) {
			q.push(make_pair(nowY, nowX));
			board[nowY][nowX] = 2;
		}
		//다음 칸이 자기 자신인 경우
		else
			break;

		//방향 변환
		if (ans == change[changeIndex].first) {
			if (change[changeIndex].second == 'D') {
				dicIndex = (dicIndex + 1 + 4) % 4;
			}
			else if (change[changeIndex].second == 'L') {
				dicIndex = (dicIndex - 1 + 4) % 4;
			}

			if (changeIndex < change.size() - 1)
				changeIndex++;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}