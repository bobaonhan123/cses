// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int res = 0;

vector<string> input(8);
vector<bool> cols(8,1);
vector<bool>d1(16,1);
vector<bool> d2(16,1);

void dq(int row) {
    if(row==8) {
        res++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if(input[row][i]!='*') {
            if(cols[i] && d1[row-i+8] && d2[i+row]) {
                cols[i] = 0;
                d1[row-i+8]=0;
                d2[i+row] =0;
                dq(row+1);
                cols[i] = 1;
                d1[row-i+8]=1;
                d2[i+row] =1;
            }
        }
    }
}

int main() {
    fast;
    for (int i = 0; i < 8; i++) {
        cin>>input[i];
    }
    dq(0);
    cout<<res;
    return 0;
}