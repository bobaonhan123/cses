// https://cses.fi/problemset/task/1643
// thuật toán kanade

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<ll>x(n);
    for (int i = 0; i < n; i++) {
        cin>>x[i];
    }
    bool ir=false;
    ll res = x[0];
    ll tmp=x[0];
    for (int i = 1; i < n; i++) {
        tmp = max(x[i],tmp+x[i]);
        res = max(res,tmp);
    }
    cout<<res;
    return 0;
}