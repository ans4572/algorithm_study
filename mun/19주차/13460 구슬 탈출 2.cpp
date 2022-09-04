// https://www.acmicpc.net/problem/13460

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

int N, M;
char board[11][11];

//왼쪽, 오른쪽, 위, 아래순
int dn[4] = { 0,0,-1,1 };
int dm[4] = { -1,1,0,0 };

class state {
public:
	int redN, redM;     //빨간 구슬 위치
	int blueN, blueM;   //파란 구슬 위치
	int count;          //횟수

	state() {}
	state(int redN, int redM, int blueN, int blueM, int count) {
		this->redN = redN;
		this->redM = redM;
		this->blueN = blueN;
		this->blueM = blueM;
		this->count = count;
	}
};

int main() {
	cin >> N >> M;

	int rN, rM, bN, bM;
	queue<state> q;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];

			//빨간 구슬과 파란 구슬 위치 저장
			if (board[i][j] == 'R') {
				rN = i;
				rM = j;
			}
			if (board[i][j] == 'B') {
				bN = i;
				bM = j;
			}
		}
	}

	q.push(state(rN, rM, bN, bM, 0));  //처음 상태 저장
	bool redFin, blueFin;

	while (!q.empty()) {
		state now = q.front();

		q.pop();

		//네 방향 확인
		for (int i = 0; i < 4; ++i) {
			redFin = false;
			blueFin = false;
			int nextRN = now.redN;
			int nextRM = now.redM;
			int nextBN = now.blueN;
			int nextBM = now.blueM;

			//다음 위치에서 벽을 만날때까지 빨간 구슬 위치 정하기
			while (board[nextRN + dn[i]][nextRM + dm[i]] != '#') {
				//만약 종료지점을 만난 경우
				if (board[nextRN + dn[i]][nextRM + dm[i]] == 'O') {
					redFin = true;
					break;
				}
				nextRN += dn[i];
				nextRM += dm[i];
			}

			//다음 위치에서 벽을 만날때까지 파란 구슬 위치 정하기
			while (board[nextBN + dn[i]][nextBM + dm[i]] != '#') {
				//만약 종료지점을 만난 경우
				if (board[nextBN + dn[i]][nextBM + dm[i]] == 'O') {
					blueFin = true;
					break;
				}
				nextBN += dn[i];
				nextBM += dm[i];
			}

			//만약 빨간 구슬만 구멍에 빠진 경우 출력 후 프로그램 종료
			if (redFin && !blueFin) {
				cout << now.count + 1 << endl;
				return 0;
			}
			//만약 파란 구슬이 구멍에 빠진 경우 실패
			else if (blueFin)
				continue;

			//만약 겹치게 되는 경우 기존의 위치를 바탕으로 구슬 하나 위치 재조정
			if (nextRN == nextBN && nextRM == nextBM) {
				//왼쪽
				if (i == 0) {
					if (now.redM < now.blueM) nextBM++;
					else nextRM++;
				}
				//오른쪽
				else if (i == 1) {
					if (now.redM < now.blueM) nextRM--;
					else nextBM--;
				}
				//위쪽
				else if (i == 2) {
					if (now.redN < now.blueN) nextBN++;
					else nextRN++;
				}
				//아래쪽
				else {
					if (now.redN < now.blueN) nextRN--;
					else nextBN--;
				}
			}

			//다음 진행이 가능한 경우 큐에 넣기
			if (now.count < 9) {
				q.push(state(nextRN, nextRM, nextBN, nextBM, now.count + 1));
			}
		}
	}

	//실패한 경우
	cout << -1 << endl;

	return 0;
}