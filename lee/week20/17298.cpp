#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> res(N, -1);
    stack<pair<int, int>> s;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        while (s.size() && s.top().first < tmp)
        {
            res[s.top().second] = tmp;
            s.pop();
        }
        s.push({ tmp, i });
    }
    for (auto it : res)
        cout << it << " ";
    cout << "\n";
}