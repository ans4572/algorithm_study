// https://www.acmicpc.net/problem/4342

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	bool turn = true;
	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;

		turn = true;

		if (a < b)
			swap(a, b);

		while (b)
		{
			// 게임이 끝나는 경우
			if (a % b == 0) {
				break;
			}
			else {
				// (b, a % b) 라는 상황이 이기든 지든 현재 턴인 사람이 무조건 이김.
				if (a / b >= 2) {
					break;
				}
				// 할 수 있는게 이거밖에 없음
				// 다음 상황을 봐야함
				else {
					a -= b;
					turn = !turn;
				}
			}

			if (a < b)
				swap(a, b);
		}

		if (turn) cout << "A wins" << endl;
		else cout << "B wins" << endl;
	}
	
	return 0;
}