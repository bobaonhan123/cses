// https://cses.fi/problemset/task/1618

/*
Để tính số chữ số 0 ở cuối của 𝑛! thì cần đếm bao nhiêu bội của 10 có trong n!.
Vì 10 = 2 × 5, mà trong giai thừa thì số bội của 2 luôn nhiều hơn số bội của 5 =>  cần đếm số lượng số 5 trong các thừa số của n!.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    fast;
    int n;
    cin>>n;
    int res=0;
    int p5=5;
    while (n>=p5)
    {
        res+=n/p5;
        p5*=5;
    }
    cout<<res;
    return 0;
}