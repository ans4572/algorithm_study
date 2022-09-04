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
			// ������ ������ ���
			if (a % b == 0) {
				break;
			}
			else {
				// (b, a % b) ��� ��Ȳ�� �̱�� ���� ���� ���� ����� ������ �̱�.
				if (a / b >= 2) {
					break;
				}
				// �� �� �ִ°� �̰Źۿ� ����
				// ���� ��Ȳ�� ������
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