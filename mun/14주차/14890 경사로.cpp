// https://www.acmicpc.net/problem/14890

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
	int N, L;

	cin >> N >> L;
	vector<vector<int> > arr(N, vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int count = 0;
	for (int i = 0; i < N; ++i) {
		bool possible = true;
		int p1 = -1, last = -1;

		if (i == 3)
			int T = 1;

		while (++p1 < N - 1) {
			// 높이 차이가 1 보다 큰 경우
			if (abs(arr[i][p1] - arr[i][p1 + 1]) > 1) {
				possible = false;
				break;
			}
			// 올라가는 경우
			else if (arr[i][p1] < arr[i][p1 + 1]) {
				// 마지막 경사로 설치 위치까지의 거리가 L 보다 큰 경우 설치 불가능
				if (p1 - last < L) {
					possible = false;
					break;
				}

				last = p1;
			}
			// 내려가는 경우
			else if (arr[i][p1] > arr[i][p1 + 1]) {
				// 남은 거리가 L 보다 작은 경우 설치 불가능
				if (N - p1 - 1 < L) {
					possible = false;
					break;
				}

				if (L > 1 && p1 + L < N) {
					for (int j = p1 + 1; j < p1 + L; ++j) {
						if (arr[i][j] != arr[i][j + 1]) {
							possible = false;
							break;
						}
					}
				}

				if (possible) {
					p1 += L - 1;
					last = p1 + 1;
				}
			}
			if (!possible)
				break;
		}

		if (possible)
			count++;

		possible = true;
		p1 = -1, last = -1;

		while (++p1 < N - 1) {
			// 높이 차이가 1 보다 큰 경우
			if (abs(arr[p1][i] - arr[p1 + 1][i]) > 1) {
				possible = false;
				break;
			}
			// 올라가는 경우
			else if (arr[p1][i] < arr[p1 + 1][i]) {
				// 마지막 경사로 설치 위치까지의 거리가 L 보다 큰 경우 설치 불가능
				if (p1 - last < L) {
					possible = false;
					break;
				}

				last = p1;
			}
			// 내려가는 경우
			else if (arr[p1][i] > arr[p1 + 1][i]) {
				// 남은 거리가 L 보다 작은 경우 설치 불가능
				if (N - p1 - 1 < L) {
					possible = false;
					break;
				}

				if (L > 1 && p1 + L < N) {
					for (int j = p1 + 1; j < p1 + L; ++j) {
						if (arr[j][i] != arr[j + 1][i]) {
							possible = false;
							break;
						}
					}
				}

				if (possible) {
					p1 += L - 1;
					last = p1 + 1;
				}
			}

			if (!possible)
				break;
		}

		if (possible)
			count++;
	}

	cout << count << endl;

	return 0;
}