// https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    string s = "";
    for (int i = 0; i < n; i++) {
        s+="0";
    }
    set<string>res;
    vector<string>res2;
    // cout<<"s:"<<s<<endl;
    while (true)
    {
        bool found = false;
        for(int i=0;i<n;i++) {
            string ss=s;
            if(ss[i]=='0')
                ss[i]='1';
            else {
                ss[i]='0';
            }
            if(res.find(ss) == res.end()) {
                res.insert(ss);
                res2.push_back(ss);
                s=ss;
                found=true;
                // cout<<s;
                break;
            }
        }
        if(!found) {
            break;
        }
    }
    // cout<<res.size()<<"\n";
    for (vector<string>::iterator it = res2.begin(); it != res2.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}