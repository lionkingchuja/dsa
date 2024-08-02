#include <bits/stdc++.h>
using namespace std;
const int v=1e5;
vector<int>parent(v);

void make(int v){
  parent[v]=v;
}

int find(int v){
  if(v==parent[v]) return v;
  else return find(parent[v]);
}

void Union(int a,int b){
   a=find(a);
   b=find(b);
  if(a !=b) parent[b]=a;
}

int main() 
{   
    int n,m;cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    while(m--){
      int a,b,wt;
      cin>>a>>b>>wt;
      edges.push_back({wt,{a,b}});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++) make(i);
    int cost=0;
    for(auto i:edges){
      int wt=i.first;
      int u=i.second.first;
      int v=i.second.second;
      if(find(u)==find(v)) continue;
      Union(u,v);
      cout<<u<<" "<<v<<endl;
      cost +=wt;
    }
    
    cout<<cost<<endl;
}