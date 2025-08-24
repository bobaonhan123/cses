// https://cses.fi/problemset/task/1723
/*
Trong ma trận kề thì nếu có đường đi trực tiếp từ i đến j, a[i][j]=1
Khi nhân ma trận với chính nó , A^2 thì A^2_i,j sẽ đếm số cách đi từ i đến j chính xác 2 bước:
Vì A^2[i][j] = sum( A[i][u] * A[u][j] for u in range[1,n])

=> Luỹ thừa k lần xong xét A^n_1,n
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)


const long long MOD = 1e9+7;

vector<vector<long long>> mulmat(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> res(a.size(), vector<long long>(b[0].size(),0));
    for(long long i=0;i<a.size();i++) {
        for(long long j=0;j<b[0].size();j++) {
            for(long long k=0;k<a[i].size();k++) {
                res[i][j]+=a[i][k]*b[k][j];
                res[i][j]%=MOD;
            }
        }
    }
    return res;
}

vector<vector<long long>> powmat(vector<vector<long long>> a, long long n) {
    if(n == 1){
        return a;
    }
    vector<vector<long long>> res = powmat(a, n / 2);
    if(n % 2 == 1){
        return mulmat(mulmat(res, res) , a);
    }
    else{
        return mulmat(res, res);
    }
}

int main() {
    fast;
    long long n,m,k;
    cin>>n>>m>>k;
    if (k == 0) {
        cout << (1 == n ? 1 : 0);
        return 0;
    }
    

    vector<vector<long long>> graph(n,vector<long long>(n,0));
    for (long long i = 0; i < m; i++) {
        long long u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u][v]++;
    }
    vector<vector<long long>> graph2 = powmat(graph,k);
    cout<<(graph2[0][n-1]+MOD)%MOD;
    return 0;
}