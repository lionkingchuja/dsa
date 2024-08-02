#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

vector<int>adj[N];
void coloring(int v){
    vector<int>result(v,-1);
    result[0]=0;

    vector<bool>used(v,false);
    set<int>st;
    for(int i=1;i<v;i++){

        for(auto it:adj[i]){
            if(result[it] !=-1) used[result[it]]=true;
        }

        int color;
        for(color=0;color<v;color++){
            if(used[color]==false) break;
        }

        result[i]=color;
        st.insert(color);
        for(auto it:adj[i]){
            if(result[it] !=-1) used[result[it]]=false;
        }
    }
    for(int i=0;i<v;i++){
        cout<<i<<"-->"<<result[i]<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    coloring(n);

}