#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B;
    cin >> A >> B;
    int cnt = 1;
    while(A < B)
    {
        cnt++;
        if(B&1)
            if(B%10 == 1)
                B /= 10;
            else
                break;
        else
            B /= 2;
    }
    if(A==B)
        cout << cnt;
    else
        cout << -1;
}
