// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    ll n;
    cin>>n;
    ll res=0;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }

    for (ll i = 1; i < n; i++) {
        if(a[i]<a[i-1]) {
            res+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout<<res;
    return 0;
}