// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    vector<bool>visited(n+1,0);
    vector<int>back(n+1,0);
    for (int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int>q;
    q.push(1);
    visited[1]=1;
    back[1]=1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < g[curr].size(); i++) {
            if(!visited[g[curr][i]]) {
                visited[g[curr][i]]=1;
                back[g[curr][i]]=curr;
                q.push(g[curr][i]);
            }
        }
    }
    
    // for (int i = 0; i < n+1; i++) {
    //     cout<<back[i]<<" ";
    // }
    stack<int>res;
    if (!visited[n]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int curr = n;
        while (true)
        {
            res.push(curr);
            if(back[curr]==curr) {
                break;
            }
            curr=back[curr];
        }
        cout<<res.size()<<endl;
        while (!res.empty())
        {
            cout<<res.top()<<" ";
            res.pop();
        }
        
    }
    return 0;
}
