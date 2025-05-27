// https://cses.fi/problemset/task/1651
/*
This is segment tree with lazy propagation
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void build(vector<ll>& smt, vector<ll>& a, ll i, ll l, ll r) {
    if (l == r) {
        smt[i] = a[l];
        return;
    }
    ll m = l + (r - l) / 2;
    build(smt, a, 2 * i + 1, l, m);
    build(smt, a, 2 * i + 2, m + 1, r);
    smt[i] = smt[2 * i + 1] + smt[2 * i + 2];
}

void propagate(vector<ll>& smt, vector<ll>& lazy, ll i, ll l, ll r) {
    if (lazy[i] != 0) {
        smt[i] += (r - l + 1) * lazy[i];
        if (l != r) {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
}

ll query(vector<ll>& smt, vector<ll>& lazy, ll i, ll l, ll r, ll L, ll R) {
    propagate(smt, lazy, i, l, r);
    if (L > r || R < l) return 0; // If (left of query is the right of r) or (Right of query is the left of l)
    if (L <= l && R >= r) return smt[i];
    ll m = l + (r - l) / 2;
    return query(smt, lazy, 2 * i + 1, l, m, L, R) + query(smt, lazy, 2 * i + 2, m + 1, r, L, R);
}

void update(vector<ll>& smt, vector<ll>& lazy, ll i, ll l, ll r, ll L, ll R, ll val) {
    propagate(smt, lazy, i, l, r);
    if (L > r || R < l) return;
    if (L <= l && R >= r) {
        lazy[i]=val;
        propagate(smt, lazy, i, l, r);
        return;
    }
    ll m = l + (r - l) / 2;
    update(smt, lazy, 2 * i + 1, l, m, L, R, val);
    update(smt, lazy, 2 * i + 2, m + 1, r, L, R, val);
}



int main() {
    fast;
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n);
    vector<ll>smt(4 * n, 0);
    vector<ll>lazy(4 * n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(smt, a, 0, 0, n - 1);
    for (ll i = 0; i < q; i++) {
        int option;
        cin >> option;
        if (option == 2) {
            ll a;
            cin >> a;
            cout << query(smt, lazy, 0, 0, n - 1, a - 1, a-1) << endl;
        }
        else {
            ll a,b,val;
            cin>>a>>b>>val;
            update(smt,lazy,0,0,n-1,a-1,b-1,val);
        }
    }

    return 0;
}
