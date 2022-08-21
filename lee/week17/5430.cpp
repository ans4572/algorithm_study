#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug
int V[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string func;
		cin >> func;
		int n;
		cin >> n;
		string S;
		cin >> S;
		stringstream st(S.substr(1, S.length() - 2));
		int idx = 0;
		while (getline(st, S, ','))
			V[idx++] = stoi(S);
		bool isFront = true;
		int l = 0;
		int r = idx;
		for (auto c : func) {
			if (c == 'R') {
				isFront = !isFront;
				continue;
			}
			else if (c == 'D') {
				if (isFront) l++;
				else r--;
			}
		}
		if (l > r) {
			cout << "error\n";
			continue;
		}
		S = "[";
		if (isFront) {
			for (int i = l; i < r; i++)
				S += to_string(V[i]) + ",";
		}
		else {
			for (int i = r - 1; i >= l; i--)
				S += to_string(V[i]) + ",";
		}
		if (S.back() == ',')
			S.back() = ']';
		else
			S.push_back(']');
		cout << S << "\n";
	}
}
