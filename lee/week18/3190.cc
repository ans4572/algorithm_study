#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int N, K, L, sec;
int mp[100][100];
queue<pair<int, char>> q;
map<char, int> M;

int status = 1;

int dr[] = {-1, 0 ,1, 0};
int dc[] = {0, 1, 0, -1};
deque<pair<int, int>> snake = {{0, 0}};

bool isContinue(){
    return snake[0].first >= 0 && snake[0].first < N && snake[0].second >= 0 && snake[0].second < N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    M['L'] = -1;
    M['D'] = 1;
    mp[0][0] = 1;

    cin >> N >> K;
    for(int i =0  ; i < K ; i++){
        int r, c;
        cin >> r >> c;
        mp[r - 1][c - 1] = 2;
    }

    cin >> L;
    while(L--) {
        int s;
        char c;
        cin >> s >> c;
        q.push({s, c});
    }

    while(isContinue()){
        if(!q.empty() && q.front().first == sec){
            status += M[q.front().second];
            if(status < 0) status = 3;
            else if(status > 3) status = 0;
            q.pop();
        }
        pair<int, int> head = snake[0];
        head.first += dr[status];
        head.second += dc[status];
        snake.push_front(head);
        sec++;
        if(mp[head.first][head.second] == 2) {
            mp[head.first][head.second] = 1;
        }
        else if (mp[head.first][head.second] == 0) {
            mp[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
            mp[head.first][head.second] = 1;
        }
        else
            break;
    }
    cout << sec << "\n";
}
