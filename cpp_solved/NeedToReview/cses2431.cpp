/*
https://cses.fi/problemset/task/2431
Ý tưởng:

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    ll k;
    cin >> k;
    ll dl = 1;
    ll cnt = 9;
    ll start = 1;
    while (k > dl * cnt) {
        k -= dl * cnt;
        dl += 1;
        cnt *= 10;
        start *= 10;
    }
    ll num = start + (k - 1)/dl; // Chỗ này k-1 là cái offset, vì sau khi đã trừ các thứ thì còn là offset
    ll idx = (k - 1) % dl;
    string number = to_string(num);
    cout << number[idx] << endl;

}

int main() {
    fast;
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}