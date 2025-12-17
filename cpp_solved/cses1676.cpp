// https://cses.fi/problemset/task/1676
/*
Input:
n: số nút, m: Số cạnh
Sau mỗi ngày sẽ xây thêm 1 cạnh
Output:
Output số component và size của component lớn nhất sau mỗi ngày
Ouput m dòng:
<Số component của ngày i> <component size lớn nhất của ngày i>
 
*/
 
#include<bits/stdc++.h>
 
using namespace std;
 
int Find(vector<int> &dsu, int u) {
    if(dsu[u]==-1) {
        return u;
    }
    return dsu[u] = Find(dsu,dsu[u]);
}
 
bool Union(vector<int>&dsu, int u,int v, vector<int>&component_size) {
    int ru = Find(dsu,u);
    int rv = Find(dsu,v);
    if(ru==rv) {
        return false;
    }
    dsu[rv]=ru;
    component_size[ru]+=component_size[rv];
    return true;
}
 
int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> dsu(n+1,-1);
    vector<int> component_size(n+1,1);
    int max_component_size = 1;
    int min_component_number = n;
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        if(Union(dsu,u,v,component_size)) {
            max_component_size = max(max_component_size, component_size[Find(dsu,u)]);
            min_component_number--;
        }
        cout<<min_component_number<<" "<<max_component_size<<endl;
    }
 
    return 0;
}
 