// https://cses.fi/problemset/task/1617
#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
    int n;
    cin>>n;
    cout<<lt(2,n);

    return 0;
}