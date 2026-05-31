//https://cses.fi/problemset/task/1077/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll sa=0,sb=0;

void balanceSet(multiset<ll>&a, multiset<ll>&b) {
    while (a.size()>b.size())
    {
        b.insert(*prev(a.end()));
        sb+=*prev(a.end());
        sa-=*prev(a.end());
        a.erase(prev(a.end()));
    }
    while (b.size()>a.size())
    {
        a.insert(*b.begin());
        sa+=*b.begin();
        sb-=*b.begin();
        b.erase(b.begin());
    }
}

void addSet(multiset<ll>&a, multiset<ll>&b, ll value) {
    if(a.empty() || value<*a.rbegin()) {
        a.insert(value);
        sa+=value;
    }
    else {
        b.insert(value);
        sb+=value;
    } 
    balanceSet(a,b);
}

void removeSet(multiset<ll>&a, multiset<ll>&b, ll value) {
    if(a.find(value)!=a.end()) {
        a.erase(a.find(value));
        sa-=value;
    }
    else {
        b.erase(b.find(value));
        sb-=value;
    }
    balanceSet(a,b);
}

int main() {
    fast;
    multiset<ll>a;
    multiset<ll>b;
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for (ll i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for (ll i = 0; i < k; i++) {
        addSet(a,b,arr[i]);
    }
    cout<<*prev(a.end())*a.size()-sa + sb - b.size()**prev(a.end())<<" ";
    for (ll i = 1; i+k-1 < n; i++) {
        addSet(a,b,arr[i+k-1]);
        removeSet(a,b,arr[i-1]);
        cout<<*prev(a.end())*a.size()-sa + sb - b.size()**prev(a.end())<<" ";
    }
    return 0;
}