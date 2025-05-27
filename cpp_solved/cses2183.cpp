// https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll res = 0;
    for(int b:a) {
        if(b>res+1) {
            break;
        }
        res+=b;
    }
    cout<<res+1;
    return 0;
}