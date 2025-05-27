// https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin >> n;
    int res = 0;
    while (n > 0) {
        res += 1;
        string sn = to_string(n);
        int max_digit = *max_element(sn.begin(), sn.end()) - '0';
        n -= max_digit;
    }
    cout<<res;
    return 0;
}