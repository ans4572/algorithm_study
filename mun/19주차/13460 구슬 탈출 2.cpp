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

//����, ������, ��, �Ʒ���
int dn[4] = { 0,0,-1,1 };
int dm[4] = { -1,1,0,0 };

class state {
public:
	int redN, redM;     //���� ���� ��ġ
	int blueN, blueM;   //�Ķ� ���� ��ġ
	int count;          //Ƚ��

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

			//���� ������ �Ķ� ���� ��ġ ����
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

	q.push(state(rN, rM, bN, bM, 0));  //ó�� ���� ����
	bool redFin, blueFin;

	while (!q.empty()) {
		state now = q.front();

		q.pop();

		//�� ���� Ȯ��
		for (int i = 0; i < 4; ++i) {
			redFin = false;
			blueFin = false;
			int nextRN = now.redN;
			int nextRM = now.redM;
			int nextBN = now.blueN;
			int nextBM = now.blueM;

			//���� ��ġ���� ���� ���������� ���� ���� ��ġ ���ϱ�
			while (board[nextRN + dn[i]][nextRM + dm[i]] != '#') {
				//���� ���������� ���� ���
				if (board[nextRN + dn[i]][nextRM + dm[i]] == 'O') {
					redFin = true;
					break;
				}
				nextRN += dn[i];
				nextRM += dm[i];
			}

			//���� ��ġ���� ���� ���������� �Ķ� ���� ��ġ ���ϱ�
			while (board[nextBN + dn[i]][nextBM + dm[i]] != '#') {
				//���� ���������� ���� ���
				if (board[nextBN + dn[i]][nextBM + dm[i]] == 'O') {
					blueFin = true;
					break;
				}
				nextBN += dn[i];
				nextBM += dm[i];
			}

			//���� ���� ������ ���ۿ� ���� ��� ��� �� ���α׷� ����
			if (redFin && !blueFin) {
				cout << now.count + 1 << endl;
				return 0;
			}
			//���� �Ķ� ������ ���ۿ� ���� ��� ����
			else if (blueFin)
				continue;

			//���� ��ġ�� �Ǵ� ��� ������ ��ġ�� �������� ���� �ϳ� ��ġ ������
			if (nextRN == nextBN && nextRM == nextBM) {
				//����
				if (i == 0) {
					if (now.redM < now.blueM) nextBM++;
					else nextRM++;
				}
				//������
				else if (i == 1) {
					if (now.redM < now.blueM) nextRM--;
					else nextBM--;
				}
				//����
				else if (i == 2) {
					if (now.redN < now.blueN) nextBN++;
					else nextRN++;
				}
				//�Ʒ���
				else {
					if (now.redN < now.blueN) nextRN--;
					else nextBN--;
				}
			}

			//���� ������ ������ ��� ť�� �ֱ�
			if (now.count < 9) {
				q.push(state(nextRN, nextRM, nextBN, nextBM, now.count + 1));
			}
		}
	}

	//������ ���
	cout << -1 << endl;

	return 0;
}