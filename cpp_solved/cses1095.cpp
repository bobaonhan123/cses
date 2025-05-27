// https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int MOD = 1e9 + 7;
long long lt(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<lt(a,b)<<endl;
    }
    
    return 0;
}