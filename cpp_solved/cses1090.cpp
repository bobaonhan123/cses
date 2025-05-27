// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    int res=0;
    while (i < j) {
        if(a[i]+a[j]<=x) {
            res++;
            i++;
            j--;
        }
        else {
            res++;
            j--;
        }
    }
    if(i==j) {
        res++;
    }
    cout<<res;

    return 0;
}