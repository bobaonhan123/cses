// https://cses.fi/problemset/task/1715


#include<bits/stdc++.h>

using namespace std;
int MOD = 1e9 + 7;
int MAXN = 2 * (1e6 + 5);

vector<long long> fact(MAXN, 1), ifact(MAXN, 1);

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

long long gt(int n) {
    return fact[n];
}

int main() {
    string s;
    cin>>s;
    vector<int> dpp(256,0);
    long long gthua = 1;
    for (int i = 2; i < MAXN; i++) {
        gthua = (gthua * i) % MOD;
        fact[i] = gthua;
    }
    ifact[MAXN - 1] = lt(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i > 0; i--) {
        ifact[i] = lt(fact[i], MOD - 2);
    }
    for(char i:s) {
        dpp[i]++;
        // cout<<i;
    }
    int tu = gt(s.size());
    int mau=1;
    for(int i:dpp) {
        if(i==0) continue;
        tu = (tu*ifact[i])%MOD;
    }
    cout<<tu;
    return 0;
}