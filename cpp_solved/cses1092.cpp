// https://cses.fi/problemset/task/1092/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll>s1, s2;
    ll n1 = 0, n2 = 0;
    while (n > 0) {
        if (n1 > n2) {
            n2 += n;
            s1.push_back(n);
        }
        else {
            n1 += n;
            s2.push_back(n);
        }
        n--;
    }
    if(n1!=n2) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        cout<<s1.size()<<endl;
        for (ll i = 0; i < s1.size(); i++) {
            cout<<s1[i]<<" ";
        }
        cout<<endl<<s2.size()<<endl;
        for (ll i = 0; i < s2.size(); i++) {
            cout<<s2[i]<<" ";
        }
    }

    return 0;
}