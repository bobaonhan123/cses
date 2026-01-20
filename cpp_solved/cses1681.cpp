//https://cses.fi/problemset/task/1681
/*
 
*/
 

#include<bits/stdc++.h>

const long long MOD=1e9+7;

using namespace std;
 
long long dq(vector<vector<long long>>& graph, vector<long long> &memory, long long node) {
    if(memory[node]!=-1) {
        return memory[node];
    }
    if(graph[node].size()==0) {
        return 0;
    }
    long long res=0;
    for(long long i=0;i<graph[node].size();i++) {
        res+=dq(graph,memory,graph[node][i]);
        res%=MOD;
    }
    memory[node]=res;
    return res;
}
 
int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>> graph(n+1);
    vector<long long> memory(n+1,-1);
    for(long long i=0;i<m;i++) {
        long long u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    memory[n]=1;
    cout<<dq(graph, memory,1);
    return 0;
}