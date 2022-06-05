#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
int max_depth=0, max_node = 0;

void dfs(int start, int depth) {
	if (visited[start]) return;
	visited[start] = true;
	
	if (max_depth < depth) { max_depth = depth; max_node = start; }

	for (int i = 0; i < tree[start].size(); i++) 
    dfs(tree[start][i].first, depth + tree[start][i].second);
}

int main() {
	int v; cin >> v;

	//데이터 입력
	for (int i = 0; i < v; i++) {
		int n1; cin >> n1;
		while(true) {
			int n2, cost;
			cin >> n2;
			if (n2 == -1) break;
			cin >> cost;
			tree[n1].push_back({ n2,cost });
		}
	}
	
  //1에서 시작해 가장 먼 거리를 가진 노드를 구함. 그리고 이 노드로부터 가장 멀리있는 노드의 거리가 지름.
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	max_depth = 0;
	dfs(max_node, 0);

	cout << max_depth;
  
  return 0;
}
