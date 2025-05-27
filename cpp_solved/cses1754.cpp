// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool solve(int a,int b) {
    if(a>b) swap(a,b);
    if(a*2<b) {
        return false;
    }
    if((a+b)%3==0) {
        return true;
    }
    return false;
}

int main() {
    fast;
    int n;
    cin>>n;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        if (solve(a,b)) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    
    return 0;
}