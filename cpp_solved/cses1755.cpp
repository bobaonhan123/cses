// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main() {
    fast;
    string s;
    cin>>s;
    vector<ll> dpp(256,0);
    for (ll i = 0; i < s.size(); i++) {
        dpp[s[i]]++;
    }
    ll le=0;
    for (ll i = 0; i < 256; i++) {
        le+=dpp[i]%2;
    }
    if(le>1) {
        cout<<"NO SOLUTION";
        return 0;
    }
    string r1="",r2="",m="";
    for (ll i = 0; i < 256; i++) {
        ll g = dpp[i] / 2;
        for (ll j = 0; j < g; j++) {
            r1 += char(i);
            r2 += char(i);
        }
        if (dpp[i] % 2 == 1) {
            m += char(i);
        }
    }
    reverse(r2.begin(), r2.end());
    cout<<r1<<m<<r2;

    return 0;
}