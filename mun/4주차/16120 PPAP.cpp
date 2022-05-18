// https://www.acmicpc.net/problem/16120

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#include<stack>

using namespace std;

int main() {
	
	string s;
	cin >> s;

	int pCount = 0;
	bool possible = true;

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'A') {
			// ppap 조건에 맞는 경우
			if (pCount >= 2 && i < s.length() - 1 && s[i + 1] == 'P') {
				pCount -= 1;
				i++;
			}
			else {
				possible = false;
				break;
			}
		}
		else
			pCount++;
	}

	if (pCount == 1 && possible)
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;

	return 0;
}