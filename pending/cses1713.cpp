// https://cses.fi/problemset/task/1713
 
#include<bits/stdc++.h>
 
using namespace std;
 
int cntdiv(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int res=2;
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0) {
            res++;
            if(n%(n/i)==0 && n/i!=i) {
                res++;
            }
        }
    }
    return res;
}
 
void solve() {
    int n;
    cin>>n;
    cout<<cntdiv(n)<<endl;
}
 
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}