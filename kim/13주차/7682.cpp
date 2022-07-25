#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

/*

x가 이기려면 -> x가 o보다 1 많아야함 (x는 3줄 있어야 함. o는 3줄 안됨)
o가 이기려면 -> o,x가 같아야 함 (x는 3줄 있으면 안됨, o는 3줄)
비긴경우 -> x==5, o==4야 함. (x,o 모두 3줄 있으면 안됨)
둘다 이긴경우 -> invalid     (x,o 3줄 모두 있는 경우)

*/


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while (true) {
		string str; cin >> str;
		int o = 0, x = 0;
		int OLines = 0, XLines = 0;	//O,X 빙고라인 갯수

		if (str == "end") break;

		for (auto val : str) {	// ox 개수 체크
			if (val == 'O') o++;
			else if (val == 'X') x++;
		}

		for (int i = 0; i < 9; i += 3) {
			if (str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {	//가로 체크
				if (str[i] == 'O') OLines++;
				else if (str[i] == 'X') XLines++;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (str[i] == str[i + 3] && str[i + 3] == str[i + 6]) {	//세로 체크
				if (str[i] == 'O') OLines++;
				else if (str[i] == 'X') XLines++;
			}
		}

		if (str[0] == str[4] && str[4] == str[8]) {					//대각선1 체크
			if (str[0] == 'O') OLines++;
			else if (str[0] == 'X') XLines++;
		}

		if (str[2] == str[4] && str[4] == str[6]) {					//대각선2 체크
			if (str[2] == 'O') OLines++;
			else if (str[2] == 'X') XLines++;
		}

		if (x == o + 1 && XLines >= 1 && OLines == 0) {

			cout << "valid" << "\n";
		}
		else if (x == o && XLines == 0 && OLines >= 1) {

			cout << "valid" << "\n";
		}
		else if (x == 5 && o == 4 && XLines == 0 && OLines == 0) {

			cout << "valid" << "\n";
		}
		else {
			cout << "invalid" << "\n";
		}


	}


	return 0;
}
