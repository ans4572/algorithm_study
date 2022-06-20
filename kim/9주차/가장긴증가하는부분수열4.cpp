#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int N; 
int arr[1001];
int length[1001];
vector<int> path[1001];
vector<int> res;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		length[i] = 1;
		path[i].push_back(arr[i]);

		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				if (length[i] < length[j] + 1) {
					path[i] = path[j];
					path[i].push_back(arr[i]);
					length[i] = length[j] + 1;
				}
				
			}
		}

		if (res.size() < path[i].size()) res = path[i];

	}

	cout << res.size() << endl;
	for (auto val : res) cout << val << " ";

}

