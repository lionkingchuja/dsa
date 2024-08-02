#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int INF=INT_MAX;
vector<int>dis(N,INF);
vector<bool>vis(N,false);

void dijkshtra(int source, vector<pair<int,int>>vp[]){
    set<pair<int,int>>s;
    s.insert({0,source});
    dis[source]=0;
    while(!s.empty()){
        auto temp=*s.begin();
        int node=temp.second;
        int wt=temp.first;
        s.erase(s.begin());
        if(vis[node]) continue;
        vis[node]=1;
        for(auto i:vp[node]){
            int new_wt=i.second;
            int new_node=i.first;
            if( dis[node] +new_wt < dis[new_node]){
                dis[new_node]=dis[node]+ new_wt;
                s.insert({dis[new_node],new_node});
            }
        }
    }

}
int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>>vp[n];
    while(m--){
        int a,b,wt;
        cin>>a>>b>>wt;
        vp[a].push_back({b,wt});
        vp[b].push_back({a,wt});
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<" ";
    //     for(auto it:vp[i]){
    //         cout<<it.first<<" "<<it.second<<endl;
    //     }
    // }
    dijkshtra(0,vp);
    for(int i=0;i<n;i++) cout<<i<<"-->"<<dis[i]<<endl;
}