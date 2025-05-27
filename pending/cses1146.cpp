// https://cses.fi/problemset/task/1146

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    int res=0;
    while (n>0)
    {
        res+= n&1;
        n>>=1;
    }
    cout<<res;
    return 0;
}