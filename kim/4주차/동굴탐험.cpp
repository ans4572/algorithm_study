#include <string>
#include <vector>
#include<iostream>
#include<queue>

using namespace std;

//위상정렬. 조건에 맞는 순서를 결정하는 알고리즘. DAG그래프여야 함. 
// 진입차수가 0인 정점을 큐에 삽입.
// 간선 제거 이후 진입차수가 0이 된 정점을 큐에 삽입
// 큐가  빌때까지 위 과정 반복. 
// 모든 원소 방문하기 전에 큐가 빈다면 사이클 존재하는 것. 


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    //단방향 그래프로 만듦.
    vector<vector<int>> vec(n);
    vector<int> result[n];
    vector<int> inDegree(n);        //진입장벽 차수
    vector<bool> check(n,false);    
    
    for(auto p : path){
        vec[p[0]].push_back(p[1]);
        vec[p[1]].push_back(p[0]);
    }
    
    queue<int> q;
    q.push(0);
    check[0]=true;
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(int next : vec[cur]){
            if(!check[next]){
                result[cur].push_back(next);
                ++inDegree[next];
                q.push(next);
                check[next]=true;
            }
        }
    }
    
    for(auto o : order){                //order의 값도 넣어줘야함.
        result[o[0]].push_back(o[1]);
        ++inDegree[o[1]];
    }
    
    if(inDegree[0]!=0) return false;
    
    //위상정렬
    q.push(0);
    for(int i=0; i<n; i++){
        if(q.empty()) return false;     //다 돌기도 전에 큐가 비면 사이클있는거므로 false.
        int cur=q.front();
        q.pop();
        for(int next : result[cur]){
            if(--inDegree[next]==0) q.push(next);   //진입장벽이 0이면 큐에 추가.
        }
    }
    
    return true;
}
