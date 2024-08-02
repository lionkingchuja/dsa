#include <bits/stdc++.h>
using namespace std;

void selection_short(vector<int>v){
  int n=v.size();
  for(int i=0;i<n;i++){
    int min_index=i;
    for(int j=i+1;j<n;j++){
      if(v[min_index] >v[j]){
        min_index=j;
      }
    }
    swap(v[i],v[min_index]);
  }
  for(auto i:v) cout<<i<<" ";
  cout<<endl;
}
int main() 
{   
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    selection_short(v);
    
}