// https://www.acmicpc.net/problem/1644

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

vector<int> primeNum;

bool isPrimeNum(int num)
{
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

void makePrimeNum(int n)
{
	for (int i = 2; i <= n; ++i) 
	{
		if (isPrimeNum(i)) {
			primeNum.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// 런타임 에러 원인
	if (N == 1) 
	{
		cout << 0 << endl;
		return 0;
	}

	// 소수 배열 만들기
	makePrimeNum(N);

	// 투포인터 활용
	int p1 = 0, p2 = 0;
	int sum = primeNum[p1];
	int ans = 0;

	while (p2 < primeNum.size())
	{
		if (sum == N)
			ans++;

		// 만약 소수의 합이 N보다 작거나 같다면 p2 증가하기
		if (sum <= N)
		{
			p2++;

			if (p2 == primeNum.size()) 
				break;

			sum += primeNum[p2];
		}
		// 만약 소수의 합이 N보다 크다면 p1 증가하기
		else if (sum > N)
		{
			sum -= primeNum[p1];
			p1++;

			if (p1 == primeNum.size())
				break;
		}
		else
			break;
	}

	cout << ans << endl;
	
	return 0;
}