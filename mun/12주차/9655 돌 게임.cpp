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

	//상근이는 항상 홀수개수 돌, 창영이는 항상 짝수 개수 돌을 가져간다.
	if (N % 2 == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;
}