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

	// mid�� �߽����� left�� �ִ���, right�� �ּ������� ����
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

		// left�� ������ right�� �������� ũ�ٸ� �߰��� ����
		if (left.size() > right.size()) {
			right.push(mid);
			mid = left.top();
			left.pop();
		}
		// left�� ����+2 �� right�� ������ ���ٴ� �� => ���� Ȧ�����ε� ������ �ʿ��ϴٴ� ��.
		else if (left.size() + 2 == right.size()) {
			left.push(mid);
			mid = right.top();
			right.pop();
		}

		cout << mid << "\n";
	}

	return 0;
}
