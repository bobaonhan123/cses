// https://cses.fi/problemset/task/1648

/*
This is a segment tree with updates to one value per update.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void build(vector<ll>& smt, ll i, ll l, ll r) {
    if (l == r) {
        smt[i] = 1;
        return;
    }
    ll m = l + (r - l) / 2;
    build(smt, 2 * i + 1, l, m);
    build(smt, 2 * i + 2, m + 1, r);
    smt[i] = smt[2 * i + 1] + smt[2 * i + 2];
}

ll query(vector<ll>& smt, ll i, ll l, ll r, ll k) {
    if(l==r) {
        return l;
    }
    ll m = l + (r - l) / 2;
    if (smt[2*i+1]>=k) {
        return query(smt, 2 * i + 1, l,m,k);
    }
    return query(smt, 2 * i + 2, m+1,r,k-smt[2 * i + 1]);
}

void update(vector<ll>& smt, ll k, ll i, ll l, ll r) {
    // smt[i]+=val;
    if (l > r) {
        return;
    }
    if(l==r) {
        smt[i]=0;
        return;
    }
    ll m = l + (r - l) / 2;
    if(k>m) {
        update(smt, k, 2 * i + 2,m+1, r);
    }
    else {
        update(smt, k, 2 * i + 1,l, m);
    }
    smt[i] = smt[2 * i + 1] + smt[2 * i + 2];
}

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll>a(n),p(n);
    vector<ll>smt(4 * n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) cin >> p[i];
    build(smt, 0, 0, n - 1);
    for (ll i = 0; i < n; i++) {
        ll k = p[i];
        ll ri = query(smt, 0, 0, n - 1, k);
        cout<<a[ri]<<" ";
        update(smt, ri, 0, 0, n - 1);

    }

    return 0;
}