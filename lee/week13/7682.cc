#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

//1. X는 O 개수 이상
//2. 둘다 이길 순 없음
//3. 마지막 수를 둬서 여러 승리 조건이 나온 게 아니라면 승리 조건은 하나여야
//4. 무승부라면 수는 다 놓아져야함
//5. X가 가능한 승리 공식 대각2개, 수평1 + 수직1, 수평1 + 대각, 수직1 + 대각
//6. o가 가능한 승리 공식 only 1
//7. x가 이기거나 비긴 경우는 x의 개수가 1개 더 많음
//8. y가 이겼을 땐 개수가 같아야함

vector<string> board;
string s;
int horizonX;
int horizonY;
int verticalX;
int verticalY;
int diagX[2];
int diagY[2];
int cntO;
int cntX;

void checkHorizon() {
    for (int i = 0; i < 3; i++)
        if (board[i] == "XXX")
            horizonX++;
        else if (board[i] == "OOO")
            horizonY++;
}

void checkVertical() {
    for (int i = 0; i < 3; i++) {
        string tmp = "";
        for(int j = 0 ; j < 3; j ++)
        tmp.push_back(board[j][i]);
        if (tmp == "XXX")
            verticalX++;
        else if (tmp == "OOO")
            verticalY++;
    }
}

void checkDiag() {
    string tmp = "";
    string tmp2 = "";
    for (int i = 0; i < 3; i++) {
        tmp += board[i][i];
        tmp2 += board[i][2 - i];
    }
    if (tmp == "XXX")
        diagX[0]++;
    else if (tmp == "OOO")
        diagY[0]++;
    if (tmp2 == "XXX")
        diagX[1]++;
    else if (tmp2 == "OOO")
        diagY[1]++;
}

void init() {
    cntO = 0;
    cntX = 0;
    horizonY = 0;
    horizonX = 0;
    verticalY = 0;
    verticalX = 0;
    memset(diagX, 0, 8);
    memset(diagY, 0, 8);
    board.emplace_back(s.substr(0, 3));
    board.emplace_back(s.substr(3, 3));
    board.emplace_back(s.substr(6));
}

bool checkCnt() {
    for (int i = 0; i < 9; i++) {
        if (s[i] == 'O') cntO++;
        else if (s[i] == 'X') cntX++;
    }
    return cntO > cntX || cntX > cntO + 1;
}

void chk() {
    checkDiag();
    checkHorizon();
    checkVertical();
}

bool isValid() {
    bool diagx = diagX[0] || diagX[1];
    bool totalx = diagx || horizonX || verticalX;
    bool diagy = diagY[0] || diagY[1];
    bool totaly = diagy || horizonY || verticalY;
    if (totaly && totalx) return false;
    if (totaly && !totalx) {
        if (cntO == cntX) return true;
        return false;
    }
    if (cntX <= cntO) return false;
    if (!totalx) {
        if (cntX + cntO == 9) return true;
        return false;
    }
    if (cntO == cntX) return false;
    //    if(diagX[0] && diagX[1]) return true;
    //    if(diagx && horizonX || diagx && verticalX) return true;
    //    if(horizonX && verticalX) return true;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //    cout << 2 || 0 ;
    while (1) {
        cin >> s;
        if (s == "end") break;
        board.clear();
        init();

        if (checkCnt()) {
            cout << "invalid\n";
            continue;
        }
        chk();
        if (isValid())
            cout << "valid\n";
        else
            cout << "invalid\n";
    }
}