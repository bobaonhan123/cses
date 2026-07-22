// https://cses.fi/problemset/task/1695

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void bfs(vector<vector<long long>> &g,vector<vector<long long>>&capacity, vector<vector<long long>> &flow, vector<long long>&trace, long long n) {
    queue<long long>q;
    q.push(1);
    for (long long i = 0; i <= n; i++) {
        trace[i]=-1;
    }

    trace[1]=0;
    while(!q.empty()) {
        long long u = q.front();
        q.pop();
        for(long long v: g[u]) {
            if(trace[v]!=-1) continue;
            if(capacity[u][v]-flow[u][v]<=0) continue;
            trace[v]=u;
            q.push(v);
        }
    }

}

void inc(vector<vector<long long>> &g,vector<vector<long long>>&capacity, vector<vector<long long>> &flow, vector<long long>&trace, long long &max_flow, long long n) {
    long long bottleneck = LLONG_MAX;
    long long v = n;
    while (v!=1)
    {
        long long u  = trace[v];
        bottleneck = min(bottleneck, capacity[u][v] - flow[u][v]);
        v = u;
    }
    
    max_flow+=bottleneck;
    v = n;
    while (v!=1)
    {
        long long u  = trace[v];
        flow[u][v]+=bottleneck;
        flow[v][u]-=bottleneck;
        v = u;
    }
}

// start: 1, terminal: n
void solve() {
    
    vector<vector<long long>> capacity(505, vector<long long>(505,0));
    vector<vector<long long>> flow(505, vector<long long>(505,0));
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> g(n+1);
    
    for (long long i = 0; i < m; i++) {
        long long a,b,c=1;
        cin>>a>>b;
        capacity[a][b]+=c;
        capacity[b][a]+=c;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    long long max_flow = 0;
    
    vector<long long>trace(n+1,0);
    while (true)
    {
        bfs(g,capacity,flow, trace,n);
        if(trace[n]==-1) break;
        inc(g,capacity,flow, trace,max_flow,n);
    }
    cout<<max_flow<<endl;
    // for (int i = 1; i <= n; i++) {
    //     cout<<trace[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(trace[i]!=-1 && trace[j]==-1 && capacity[i][j]!=0) {
                cout<<i<<" "<<j<<endl;
            }
        }
    }

}

int main() {
    fast;
    long long t = 1;
    while (t--) {
        solve();
    }
    return 0;
}