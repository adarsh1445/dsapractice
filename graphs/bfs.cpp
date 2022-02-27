#include<bits/stdc++.h>
using namespace std;


void dfsg(vector<int> adj[],vector<bool> &vis,int s){
 
      vis[s] = true;
      
      cout<<s<<"\n";
      for(auto i : adj[s]){
         if(!vis[i]){
         dfsg(adj,vis,i);}
      }
     
}

void dfs(vector<int> adj[],int n, int s){
     
      vector<bool> visited(n+1,false);
      dfsg(adj,visited,s);
}

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0 ; i<m ; i++){
             int u,v;
             cin>>u>>v;
             adj[u].push_back(v);
           
    }

    dfs(adj,n,0);
}
