#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info {
	int dist; 
	int idx;
	int idx2;
};

vector<Info> vec;
int parent[100001];

bool cmp(Info a, Info b) {
	return a.dist < b.dist;
}

int findParent(int a) {
	if (parent[a] == a) return a;	//자기 자신이 부모인 경우 
	else return parent[a] = findParent(parent[a]);	//부모를 찾는다.
}

bool isCycle(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b) return true;	//사이클 확인 : 부모가 같다면 사이클이 형성된것.
	else {
		parent[a] = b;			//부모 지정
		return false;
	}
}


int main() {
	int N; cin >> N;
	
	vector<pair<int,int>> vecX;
	vector<pair<int, int>> vecY;
	vector<pair<int, int>> vecZ;

	for (int i = 0; i < N; i++) {
		int x, y, z; cin >> x >> y >> z;
		vecX.push_back({ x,i });
		vecY.push_back({ y,i });
		vecZ.push_back({ z,i });
		parent[i] = i;
	}
	
	sort(vecX.begin(), vecX.end());
	sort(vecY.begin(), vecY.end());
	sort(vecZ.begin(), vecZ.end());

	for (int i = 0; i < N - 1; i++) {
		vec.push_back({ vecX[i + 1].first - vecX[i].first,vecX[i].second,vecX[i + 1].second });
		vec.push_back({ vecY[i + 1].first - vecY[i].first,vecY[i].second,vecY[i + 1].second });
		vec.push_back({ vecZ[i + 1].first - vecZ[i].first,vecZ[i].second,vecZ[i + 1].second });
	}

	sort(vec.begin(), vec.end(),cmp);

	int res = 0;
	for (auto val : vec) {
		if (!isCycle(val.idx, val.idx2)) res += val.dist;
	}

	cout << res;

	return 0;
}
