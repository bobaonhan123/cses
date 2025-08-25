// https://cses.fi/problemset/task/1675
/*
min spanning tree
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll find(vector<ll>&dsu,ll a) {
    if(dsu[a]==-1) {
        return a;
    }
    return dsu[a]=find(dsu,dsu[a]);
}

void uia(vector<ll>&dsu,ll a,ll b) {
    ll ra=find(dsu,a);
    ll rb=find(dsu,b);
    dsu[rb]=ra;
}

struct node {
    ll u,v,w;
};

int main() {
    fast;
    ll n,m;
    cin>>n>>m;
    vector<ll> dsu(n+1,-1);
    vector<node>g(m);
    for (ll i = 0; i < m; i++) {
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    sort(g.begin(), g.end(), [](const node& a, const node& b) {
        return a.w < b.w;
    });
    ll res=0;
    ll used = 0;
    for (ll i = 0; i < m; i++) {
        if(find(dsu,g[i].u)!=find(dsu,g[i].v)) {
            res+=g[i].w;
            used++;
            uia(dsu,g[i].u,g[i].v );
        }
    }
    if (used != n - 1) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<res;
    return 0;
}