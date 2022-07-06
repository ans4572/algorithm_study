// https://www.acmicpc.net/problem/2023

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int N;

// 소수 판별 함수
bool isPrimeNum(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// 백트래킹 활용
void DFS(int idx, int num) {
	if (idx == N) {
		cout << num << endl;
	}
	else {
		int tmp = num * 10;
		for (int i = 1; i < 10; ++i) {
			if (isPrimeNum(tmp + i)) {
				DFS(idx + 1, tmp + i);
			}
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	DFS(1, 2);
	DFS(1, 3);
	DFS(1, 5);
	DFS(1, 7);

	return 0;
}
