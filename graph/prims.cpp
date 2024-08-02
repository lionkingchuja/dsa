#include <bits/stdc++.h>
using namespace std;

int sum=0;
void prims(vector<pair<int,int>>vp[],int n){
  
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<bool>vis(n,false);
  // {wt,node}
  pq.push({0,0});
  
  while(!pq.empty()){
    auto temp=pq.top();
    pq.pop();
    int node=temp.second;
    int wt=temp.first;
    
    if(vis[node]==true) continue;
    vis[node]=true;
    sum +=wt;
    
    for(auto i:vp[node]){
      int adjnode=i.first;
      int adjwt=i.second;
      if(vis[adjnode]==false) pq.push({adjwt,adjnode});
    }
  }
  
  cout<<sum;
}

int main() 
{   
    int n,m;cin>>n>>m;
    vector<pair<int,int>>vp[n];
    while(m--){
      int a,b,wt;
      cin>>a>>b>>wt;
      vp[a].push_back({b,wt});
      vp[b].push_back({a,wt});
    }
    for(int i=0;i<n;i++){
      cout<<i<<"-->";
      for(auto j:vp[i]) cout<<j.first<<","<<j.second<<" ";
      cout<<endl;
    }
    
    prims(vp,n);
    
}