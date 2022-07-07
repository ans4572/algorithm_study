#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int n;

bool isPrime(int num) {	//소수 판별
	if (num < 2) return false;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) return false;
	}

	return true;
}

void start(int num, int digit) {	//숫자 , 자릿수
	if (digit == n) {
		cout << num << "\n";
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (isPrime(num * 10 + i))	// 자릿수 증가.
			start(num * 10 + i, digit + 1);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	// 맨 앞자리 수는 2,3,5,7만 올 수 있음. 

	start(2,1);
	start(3,1);
	start(5,1);
	start(7,1);
	
	return 0;
}
