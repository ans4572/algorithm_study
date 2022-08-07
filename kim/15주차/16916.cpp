#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;

vector<int> getFailFunc(string p) {
	vector<int> failVec(p.length());
	int j = 0;
	for (int i = 1; i < p.length(); i++) {	//fail배열의 0번재는 무조건 0.
		while (p[i] != p[j] && j > 0) j = failVec[--j];	// 0혹은 문자열 다르면 j 위치 조절함.(실패함수 전단계의 값)
		if (p[i] == p[j]) failVec[i] = ++j;				// 문자열 같으면 i와 j 증가시키면서 비교함.
	}

	return failVec;
}

int KMP(string s, string p) {
	vector<int> failVec = getFailFunc(p);
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (s[i] != p[j] && j > 0) j = failVec[--j];	// 문자열 다르면 실패함수 참고후 이동
		if (s[i] == p[j]) {									// 문자열 같으면
			if (++j == p.length()) return 1;	//찾음		// 끝까지 비교했으면 1 리턴
		}
	}
	return 0;	//실패
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s, p;
	cin >> s >> p;

	//실패함수 도입 : 문자 매칭에 실패시 얼만큼 건너뛰어야 하는가? (실패 이전 상황에서 접두사, 접미사 일치한 최대 길이 만큼 이동)
	//실패함수 구하는법 : i와 j가 가리키는 문자열이 같으면 이전 값에서 1을 더함, 다르면 이전값 참고
	//실패함수 이용방법 : 문자 탐색중에 불일치 구간이 나오면 이전 인덱스의 실패함수 만큼 배열 이동.

	cout << KMP(s, p);

	return 0;
}
