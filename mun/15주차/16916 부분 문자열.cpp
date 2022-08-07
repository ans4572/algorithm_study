// https://www.acmicpc.net/problem/16916

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

// 그냥 풀면 시간초과..
// kmp 알고리즘 활용: https://bowbowbow.tistory.com/6

// 건너뛸때 도와주는 pi 배열 생성 함수
vector<int> getPi(string p) {
	vector<int> pi(p.size(), 0);
	int j = 0;

	for (int i = 1; i < p.size(); ++i) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

bool kmp(string s, string p) {
	vector<int> pi = getPi(p);
	int j = 0;

	for (int i = 0; i < s.size(); ++i) {
		// 중간 단계를 건너뛰어 탐색 위치 찾기
		// 최대한 뛰어 넘기위해 반복문 사용
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];

		if (s[i] == p[j]) {
			if (j == p.size() - 1) {
				return 1;
			}
			else j += 1;
		}
	}

	return 0;
}

int main() {

	string S, P;
	cin >> S >> P;

	cout << kmp(S, P) << endl;

	return 0;
}