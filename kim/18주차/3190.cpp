#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

int n,k,l;
int table[101][101];
bool isSnake[101][101];			// 뱀의 몸통 유무 파악. (1이면 뱀 있음)
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int cur_dir = 0;				//현재 방향
char order[10001];				// D : 오른쪽으로 90도 회전 , L : 왼쪽으로 90도 회전
queue<pair<int, int>> snake;	// 좌표 저장. 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		table[r][c] = 1;	// 맵에 사과표시
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int x; char ch; cin >> x >> ch;
		order[x] = ch;
	}


	snake.push({ 1,1 });	// 1,1서 시작
	isSnake[1][1] = true;		// 뱀 삽입

	int res = 0;
	while (true) {

		res++;

		int hx = snake.back().first + dir[cur_dir][0];
		int hy = snake.back().second + dir[cur_dir][1];

		if (hx<1 || hx>n || hy<1 || hy>n) break;	// 벽 부딫히면 종료
		if (isSnake[hx][hy]) break;	// 몸통에 부딫히면 종료

		snake.push({ hx,hy });
		isSnake[hx][hy] = true;

		//방향 전환
		if (order[res] == 'L') {
			cur_dir -= 1;
			if (cur_dir == -1) cur_dir = 3;
		}
		else if (order[res] == 'D') {
			cur_dir += 1;
			if (cur_dir == 4) cur_dir = 0;
		}

		if (table[hx][hy] == 1) {	//사과 있으면 먹고, 꼬리 움직이지 않음
			table[hx][hy] = 0;
		}
		else {		// 사과 없으면 꼬리 없엠
			isSnake[snake.front().first][snake.front().second] = false;
			snake.pop();
		}

	}

	cout << res;

	return 0;
}
