// https://www.acmicpc.net/problem/7682

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

char board[3][3];

bool isWin(char xo) {
	for (int i = 0; i < 3; ++i)
		if (board[i][0] == xo && board[i][1] == xo && board[i][2] == xo)
			return true;
	for (int i = 0; i < 3; ++i)
		if (board[0][i] == xo && board[1][i] == xo && board[2][i] == xo)
			return true;
	if (board[0][0] == xo && board[1][1] == xo && board[2][2] == xo)
		return true;
	if (board[0][2] == xo && board[1][1] == xo && board[2][0] == xo)
		return true;

	return false;
}

int main() {

	string input;
	while (cin >> input) {
		if (input == "end") break;

		int xCount = 0, oCount = 0;
		bool xWin = false, oWin = false;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				board[i][j] = input[i * 3 + j];

				if (board[i][j] == 'X') xCount++;
				if (board[i][j] == 'O') oCount++;
			}
		}

		xWin = isWin('X');
		oWin = isWin('O');

		// x�� �̱�� ���
		// x�� �̱�鼭 o�� ���� x�� ���� o�� ������ 1�� �� ���ƾ���
		if (xWin && !oWin && xCount == oCount + 1)
			cout << "valid" << endl;
		// o�� �̱�� ���
		// o�� �̱�鼭 x�� ���� o�� ���� x�� ���� ���ƾ���
		else if (!xWin && oWin && xCount == oCount)
			cout << "valid" << endl;
		// ���� ���
		// �� �� ���鼭 ������ �������¿�����
		else if (!xWin && !oWin && xCount == 5 && oCount == 4)
			cout << "valid" << endl;
		// �� ��
		else
			cout << "invalid" << endl;
	}

	return 0;
}