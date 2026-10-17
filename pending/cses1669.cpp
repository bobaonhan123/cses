/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, deque<int> &res, vector<bool> &visited, vector<bool> &blocked, int u, bool &found, set<int>&inStack) {
    inStack.insert(u);
    if(found) return;
    visited[u]=true;
    res.push_back(u);
    if(graph[u].size()==0) {
        blocked[u] = 1;
        res.pop_back();
        inStack.erase(u);
        return;
    }
    bool block = true;
    for(int i:graph[u]) {
        if (i==res.back()) continue;
        
        if(!blocked[i]){ 
            block = false;
            if(!visited[i]) {
                dfs(graph,res,visited,blocked,i,found, inStack);
            }
            else if (inStack.find(i)!=inStack.end()) {
                found = true;
                res.push_back(i);
                return;
            }
        }
        if (found) return;
    }
    blocked[u]=1;
    res.pop_back();
    inStack.erase(u);
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n+1,false);
    vector<bool> blocked(n+1,false);
    set<int>inStack;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    deque<int>res;
    bool found = false;
    
    dfs(graph,res,visited,blocked, 1, found, inStack);
    bool stop=false;
    while(!found && !stop) {
        stop=true;
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                stop = false;
                res.clear();
                dfs(graph,res,visited,blocked, i, found, inStack);
                if(found) break;
            }
        }
    }
    
    if(!found) {cout<<"IMPOSSIBLE"; return 0;}
    while(res.front()!=res.back()) {
        res.pop_front();
    }
    vector<int> ress;
    
    while(!res.empty()) {
        ress.push_back(res.front());
        res.pop_front();
    }
    
    cout<<ress.size()<<endl;
    for(int v:ress) {
        cout<<v<<" ";
    }
    return 0;
}