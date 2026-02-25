//https://cses.fi/problemset/task/1076/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void balanceSet(multiset<int>&a, multiset<int>&b) {
    while (a.size()>b.size())
    {
        b.insert(*prev(a.end()));
        a.erase(prev(a.end()));
    }
    while (b.size()>a.size())
    {
        a.insert(*b.begin());
        b.erase(b.begin());
    }
}

void addSet(multiset<int>&a, multiset<int>&b, int value) {
    if(a.empty() || value<*a.rbegin()) a.insert(value);
    else b.insert(value);
    balanceSet(a,b);
}

void removeSet(multiset<int>&a, multiset<int>&b, int value) {
    if(a.find(value)!=a.end()) {
        a.erase(a.find(value));
    }
    else {
        b.erase(b.find(value));
    }
    balanceSet(a,b);
}

int main() {
    fast;
    multiset<int>a;
    multiset<int>b;
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i < k; i++) {
        addSet(a,b,arr[i]);
    }
    cout<<*prev(a.end())<<" ";
    for (int i = 1; i+k-1 < n; i++) {
        addSet(a,b,arr[i+k-1]);
        removeSet(a,b,arr[i-1]);
        cout<<*prev(a.end())<<" ";
    }
    return 0;
}