// https://www.acmicpc.net/problem/9655

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int main() {
	int N;
	cin >> N;

	//����̴� �׻� Ȧ������ ��, â���̴� �׻� ¦�� ���� ���� ��������.
	if (N % 2 == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;
}