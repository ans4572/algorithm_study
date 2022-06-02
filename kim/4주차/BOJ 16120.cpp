#include<iostream>
#include<cmath>
#include<stack>
#include<string>
using namespace std;

int main() {

	string str; cin >> str;
	stack<char> res;

	for (int i = 0; i < str.length(); i++) {

		if (str[i] == 'P') res.push('P');
		else {		//'A'
			if (res.size() >= 2 && str[i + 1] == 'P') {
				res.pop();
				i++;
			}
			else {	//PPPPAAP 같은경우
				cout << "NP" << endl;
				return 0;
			}
		}
	}

	if (res.size() == 1) cout << "PPAP" << endl;
	else cout << "NP" << endl;
}
