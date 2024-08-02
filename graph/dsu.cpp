//connected component counts
#include<bits/stdc++.h>
using namespace std;
const int n=1e5;
vector<int>parent(n);
vector<int>size(n);
void make(int i){
    parent[i]=i;
    size[i]=1;
}

int find(int i){
    if(parent[i]==i) return i;
    //path compression
    return parent[i]=find(parent[i]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        //union by size
        if(size[a] > size[b]){
            parent[b]=a;
            size[a] +=size[b];
        }
        else {
            parent[a]=b;
            size[b] +=size[a];
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) make(i);

    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    int connected_com=0;
    for(int i=1;i<=n;i++){
        if(parent[i]==i) connected_com++;
    }
    cout<<connected_com<<endl;


    return 0;
}