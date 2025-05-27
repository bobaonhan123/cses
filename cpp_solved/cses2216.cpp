// https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>pos(n+1,0);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    int res=1;
    for (int i = 2; i <= n; i++) {
        if(pos[i]<pos[i-1]) {
            res++;
        }
    }
    cout<<res;
    return 0;
}