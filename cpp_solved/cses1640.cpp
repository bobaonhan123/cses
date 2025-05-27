// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i].second;
        a[i].first=i;
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });
    int i=0,j=n-1;
    int l=-1,r=-1;
    while (i<j)
    {
        if(a[i].second+a[j].second==x) {
            l=a[i].first;r=a[j].first;
            break;
        }
        if(a[i].second+a[j].second>x) {
            j--;
        }
        else {
            i++;
        }
    }
    if(l==-1) {
        cout<<"IMPOSSIBLE";
    }
    else {
        cout<<l+1<<" "<<r+1;
    }
    return 0;
}