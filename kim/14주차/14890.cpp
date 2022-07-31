#include<iostream>
#include<vector>
using namespace std;

int N, L;
int map[101][101];

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 1. 높이 차이 2 이상인경우 , 2. L길이가 땅보다 더 긴 경우 , 3. 경사로 겹치는 경우
	
	int res = 2 * N;

	for (int i = 0; i < N; i++) {

		int sameCnt = 1;		//같은 높이의 연속된 계단인 경우 1씩 증가
		bool canGo = true;	//지나갈 수 있는지 여부

		for (int j = 0; j + 1 < N; j++) {
			if (map[i][j] == map[i][j + 1]) sameCnt++;
			else if (map[i][j] - map[i][j + 1] == -1) {	//올라가는 계단
				if (sameCnt < L) canGo = false;
				else sameCnt = 1;
				
			}
			else if (map[i][j] - map[i][j + 1] == 1) {	//내려가는 계단
				if (sameCnt < 0) canGo = false;
				else sameCnt = -(L - 1);	//미리 경사로 길이만큼 빼둠. 그리고 계속 진행하면서, 연속된 길이가 경사로 길이보다 짧다면 음수로 나올것
			}
			else canGo = false;
		}

		if (!canGo || sameCnt < 0) res--;
	}

	for (int i = 0; i < N; i++) {
		
		int sameCnt = 1;
		bool canGo = true;

		for (int j = 0; j + 1 < N; j++) {
			if (map[j][i] == map[j + 1][i]) sameCnt++;
			else if (map[j][i] - map[j + 1][i] == -1) {
				if (sameCnt < L) canGo = false;
				else sameCnt = 1;
			}
			else if (map[j][i] - map[j + 1][i] == 1) {
				if (sameCnt < 0) canGo = false;
				else sameCnt = -(L - 1);
			}
			else canGo = false;
		}
		if (!canGo || sameCnt < 0) res--;
	}

	cout << res;

	return 0;
}
