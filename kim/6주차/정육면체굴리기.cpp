#include<iostream>
#include<tuple>

using namespace std;

int n,m;
int x,y;
int k;

int map[21][21];

int dice[7]={0,0,0,0,0,0,0};
int dir[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}}; //동 서 북 남

int u=1, f=2, r=3;              //up , front, right

void start(int d){

    int nx=x+dir[d][0];
    int ny=y+dir[d][1];

    if(0>nx || 0>ny || nx>=n || ny>=m) return;      //범위 체크

    x=nx;
    y=ny;

    if(d==1){         //동
        int nu = 7-r;
        r=u;
        u=nu;
    }else if(d==2){   //서
        int nu = r;
        r = 7-u;
        u=nu;
    }else if(d==3){   //북
        int nu = f;
        f = 7-u;
        u=nu;
    }else{              //남
        int nu = 7-f;
        f=u;
        u=nu;
    }

    if(map[x][y]==0) map[x][y]=dice[7-u];   //칸이 0이면 주사위 값 복사
    else{                                   //칸이 0이 아닌경우, 주사위에 복사하고 0으로
        dice[7-u]=map[x][y];
        map[x][y]=0;
    }

    cout<<dice[u]<<endl;
}

int main(){

    cin>>n>>m>>x>>y>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        int dir; cin>>dir;
        start(dir);
    }

    return 0;
}
