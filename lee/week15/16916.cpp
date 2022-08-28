#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string S, P;
	cin >> S >> P;
	const char* s = S.c_str();
	const char* p = P.c_str();

	if (strstr(s, p)) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
}
