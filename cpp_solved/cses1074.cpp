// https://cses.fi/problemset/task/1074
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==1) {
        cout<<0;
        return 0;
    }
    int m1 = a[int(n/2)-1];
    int m2 = a[int(n/2)];
    ll r1=0;
    ll r2=0;
    for (int i = 0; i < n; i++) {
        r1+=abs(a[i]-m1);
        r2+=abs(a[i]-m2);
    }
    cout<<min(r1,r2);
    return 0;
}