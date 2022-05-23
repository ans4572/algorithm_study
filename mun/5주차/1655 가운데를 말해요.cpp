// https://www.acmicpc.net/problem/1655

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	// mid를 중심으로 left는 최대힙, right는 최소힙으로 구성
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;

	int mid;
	cin >> mid;
	cout << mid << "\n";

	int input;
	for (int i = 1; i < N; ++i) {
		cin >> input;
		if (mid >= input) left.push(input);
		else right.push(input);

		// left의 개수가 right의 개수보다 크다면 중간값 갱신
		if (left.size() > right.size()) {
			right.push(mid);
			mid = left.top();
			left.pop();
		}
		// left의 개수+2 가 right의 개수와 같다는 것 => 현재 홀수개인데 갱신이 필요하다는 것.
		else if (left.size() + 2 == right.size()) {
			left.push(mid);
			mid = right.top();
			right.pop();
		}

		cout << mid << "\n";
	}

	return 0;
}
