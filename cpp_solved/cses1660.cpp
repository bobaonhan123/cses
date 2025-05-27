// https://cses.fi/problemset/task/1660
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    // sort(a.begin(),a.end());
    int i=0,j=0;
    int su=0;
    int res=0;
    while (j<=n)
    {
        if(su>x) {
            su-=a[i];
            i++;
        }
        else if(su<x) {
            su+=a[j];
            j++;
        }
        else {
            res++;
            su-=a[i];
            i++;
            su+=a[j];
            j++;
        }
    }
    cout<<res;
    
    return 0;
}