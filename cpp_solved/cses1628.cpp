#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<ll> getSubSet(vector<ll>&a) {
    ll n = a.size();
    vector<ll>res;
    for(ll mask=1; mask < (1LL<<n); mask++) {
        ll su = 0;
        for(ll j=0;j<n;j++) {
            if(mask & (1<<j)) {
                su+=a[j];
            }
        }
        res.push_back(su);
    }
    return res;
}

void solve() {
    ll n, x;
    cin>>n>>x;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll k = n/2;
    vector<ll>left(a.begin(), a.begin() + k);
    vector<ll>right(a.begin()+k, a.end());
    vector<ll> sLeft = getSubSet(left);
    vector<ll> sRight = getSubSet(right);
    ll res = 0;
    
    sort(sRight.begin(), sRight.end());
    for(ll i=0;i<sLeft.size();i++) {
        if(sLeft[i]==x) {
            res++;
        }
    }
    for(ll i=0;i<sRight.size();i++) {
        if(sRight[i]==x) {
            res++;
        }
    }
    for(ll i=0;i<sLeft.size();i++) {
        ll target = x - sLeft[i];
        auto L = lower_bound(sRight.begin(), sRight.end(), target);
        auto R = upper_bound(sRight.begin(), sRight.end(), target);
        res+=R - L;
    }
    //debug
    // cout<<endl;
    // for(ll i=0;i<sLeft.size();i++) {
    //     cout<<sLeft[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0;i<sRight.size();i++) {
    //     cout<<sRight[i]<<" ";
    // }
    // cout<<endl;
    //endebug
    cout<<res;

}

int main() {
    fast;
    ll t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}