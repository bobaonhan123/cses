// https://cses.fi/problemset/task/1649

/*
This is a segment tree with updates to one value per update. But minimum instead of sum
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll MAXN = 1e9+7;

void build(vector<ll>& smt, vector<ll>& a, ll i, ll l, ll r) {
    if (l == r) {
        smt[i] = a[l];
        return;
    }
    ll m = l + (r - l) / 2;
    build(smt, a, 2 * i + 1, l, m);
    build(smt, a, 2 * i + 2, m + 1, r);
    smt[i] = min(smt[2 * i + 1], smt[2 * i + 2]);
}

ll query(vector<ll>& smt, ll i, ll l, ll r, ll L, ll R) {
    if (L > r || R < l) return MAXN; // If (left of query is the right of r) or (Right of query is the left of l)
    if (L <= l && R >= r) return smt[i];
    ll m = l + (r - l) / 2;
    return min(query(smt, 2 * i + 1, l, m, L, R), query(smt, 2 * i + 2, m + 1, r, L, R));
}

void update(vector<ll>& smt, ll k, ll val, ll i, ll l, ll r) {
    if (l == r) {
        smt[i] = val;
        return;
    }
    ll m = (l + r) / 2;
    if (k <= m)
        update(smt, k, val, 2*i + 1, l, m);
    else
        update(smt, k, val, 2*i + 2, m+1, r);
    smt[i] = min(smt[2*i + 1], smt[2*i + 2]);
}

int main() {
    fast;
    ll n, q;
    cin >> n >> q;
    vector<ll>a(n);
    vector<ll>smt(4 * n, MAXN);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(smt, a, 0, 0, n - 1);
    for (ll i = 0; i < q; i++) {
        int choice;
        cin >> choice;
        if (choice == 2) {
            ll a, b;
            cin >> a >> b;
            cout << query(smt, 0, 0, n - 1, a - 1, b - 1) << endl;
        }
        else {
            ll k,u;
            cin>>k>>u;
            update(smt,k-1,u,0,0,n-1);
            a[k - 1] = u;
        }
    }

    return 0;
}