// https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void build(vector<ll>&smt,vector<ll>& a, ll i, ll l, ll r) {
    if (l == r) { 
        smt[i] = a[l];
        return;
    }
    ll m = l + (r - l) / 2;
    build(smt,a, 2 * i + 1, l, m);
    build(smt,a, 2 * i + 2, m + 1, r);
    smt[i] = max(smt[2 * i + 1], smt[2 * i + 2]);
}

int query(vector<ll>&smt,vector<ll>& a, ll i, ll l, ll r, ll val) {
    if(smt[i]<val) {
        return -1;
    }
    if(l==r) {
        return l;
    }
    ll m = l + (r - l) / 2;
    if(smt[2*i+1]>=val) {
        return query(smt,a, 2 * i + 1, l, m, val);
    }
    return query(smt,a, 2 * i + 2, m+1, r, val);
}

void update(vector<ll>& smt, int i, int l, int r, int pos, ll newVal) {
    if (l == r) {
        smt[i] = newVal;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        update(smt, 2*i+1, l,   m,   pos, newVal);
    else
        update(smt, 2*i+2, m+1, r,   pos, newVal);
    smt[i] = max(smt[2*i+1], smt[2*i+2]);
}


int main() {
    fast;
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<ll>smt(4*n,0);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    build(smt,a,0,0,n-1);
    for (ll i = 0; i < m; i++) {
        int p;
        cin>>p;
        int idx = query(smt,a ,0, 0, n-1, p);
        cout<<idx+1<<" ";
        if(idx!=-1) {
            a[idx] -=p;
            update(smt, 0, 0, n-1, idx, a[idx]);
        }
    }
    return 0;
}