// https://programmers.co.kr/learn/courses/30/lessons/67260
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>
#include<stack>

using namespace std;

const int maxN = 200001;

vector<int> edge[maxN];     // ����� �׷���
vector<int> delay(maxN);    // �̷� ��� ����
vector<int> before(maxN);   // ���� �湮�ؾ��ϴ� ��� ����
vector<bool> visit(maxN);   

void DFS(int num) {
	// �̹� �湮�� ���
	if (visit[num]) return;

	// num ������ �湮�ؾ� �� ���� ���� �湮���� ���� ���
	if (!visit[before[num]]) {
		delay[before[num]] = num;
		return;
	}

	visit[num] = true;
	DFS(delay[num]);

	for (int n : edge[num])
		DFS(n);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	for (auto iter : path) {
		edge[iter[0]].push_back(iter[1]);
		edge[iter[1]].push_back(iter[0]);
	}

	for (auto iter : order) {
		before[iter[1]] = iter[0];
	}

	// 0�� ��带 �ʰ� �湮�ϴ� ���
	if (before[0])
		return false;

	// 0�� ����� DFS ����
	visit[0] = true;
	for (int n : edge[0])
		DFS(n);

	// ��� ���� Ž���ߴ��� Ȯ��
	for (int i = 0; i < n; ++i) {
		if (!visit[i])
			return false;
	}

	return true;
}

int main() {

	string s;
	cin >> s;



	return 0;
}