#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(void) {
    
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		deque<int> d; string p, arr,tmp; int n;
		bool isReverse = false, isError = false;
		cin >> p >> n >> arr; //함수 p, 배열 크기, 배열 값
	
		//arr 배열 덱에 저장
		for (int j = 0; j < arr.length(); j++) { 
			if (arr[j] == '[') continue;
			else if (arr[j] >= '0' && arr[j] <= '9') tmp += arr[j];
			else if ((arr[j] == ',' || arr[j] == ']')&& tmp!="") {
				d.push_back(stoi(tmp));
				tmp.clear();
			}
		}

		//p 함수 실행
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') isReverse = !isReverse;
			else {
				if (d.empty()) { isError=true; break; }
				if (isReverse) d.pop_back();
				else d.pop_front();
			}
		}

		if (isError) cout << "error\n";
		else if (d.empty()) cout << "[]\n";
		else if (isReverse) {
			cout << "[";
			while (d.size()>1) {
				cout << d.back() << ",";
				d.pop_back();
			}
			cout << d.back() << "]\n";
		}
		else {
			cout << "[";
			while (d.size() > 1) {
				cout << d.front() << ",";
				d.pop_front();
			}
			cout << d.front() << "]\n";
		}
	}
}
