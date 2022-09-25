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

	// ��Ÿ�� ���� ����
	if (N == 1) 
	{
		cout << 0 << endl;
		return 0;
	}

	// �Ҽ� �迭 �����
	makePrimeNum(N);

	// �������� Ȱ��
	int p1 = 0, p2 = 0;
	int sum = primeNum[p1];
	int ans = 0;

	while (p2 < primeNum.size())
	{
		if (sum == N)
			ans++;

		// ���� �Ҽ��� ���� N���� �۰ų� ���ٸ� p2 �����ϱ�
		if (sum <= N)
		{
			p2++;

			if (p2 == primeNum.size()) 
				break;

			sum += primeNum[p2];
		}
		// ���� �Ҽ��� ���� N���� ũ�ٸ� p1 �����ϱ�
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