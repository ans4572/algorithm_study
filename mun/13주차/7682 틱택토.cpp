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

		// x가 이기는 경우
		// x가 이기면서 o는 지고 x의 수가 o의 수보다 1개 더 많아야함
		if (xWin && !oWin && xCount == oCount + 1)
			cout << "valid" << endl;
		// o가 이기는 경우
		// o가 이기면서 x는 지고 o의 수와 x의 수가 같아야함
		else if (!xWin && oWin && xCount == oCount)
			cout << "valid" << endl;
		// 비기는 경우
		// 둘 다 지면서 개수가 최종상태여야함
		else if (!xWin && !oWin && xCount == 5 && oCount == 4)
			cout << "valid" << endl;
		// 그 외
		else
			cout << "invalid" << endl;
	}

	return 0;
}