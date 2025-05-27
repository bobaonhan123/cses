// https://cses.fi/problemset/task/3314
/*
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>prev(n,0);
    vector<int>ma(n,0);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    ma[0]=a[0];
    int res=0;
    for (int i = 1; i < n; i++) {
        if(a[i]<ma[i-1]) {
            ma[i]=ma[i-1];
            prev[i]=prev[i-1];
        }
        else {
            ma[i]=a[i];
            prev[i]=i;
        }
    }
    for (int i = 0; i < n; i++) {
        res=max(res,i-prev[i]+1);
    }
    cout<<res;
    return 0;
}