// https://cses.fi/problemset/task/1620
/*
Binary search in time
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll calculate(const vector<ll>& a, ll time, ll k) {
    ll res = 0;
    for (ll p : a) {
        res += time / p;
        if (res >= k) return res;
    }
    return res;
}


int main() {
    fast;
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll maxtime = 1e18;
    ll l=0;
    ll r=maxtime;
    while (l<r)
    {
        ll m = (l+r)/2;
        if(calculate(a,m, k) < k) {
            l=m+1;
        }
        else {
            r=m;
        }
    }
    cout<<r;
    return 0;
}