#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;

  cin>>n>>m;

  vector<pair<int,int>> graph[n+1];

  for(int i = 0 ; i < m; i++){
         int u,v,wt;
         cin>>u>>v>>wt;
         graph[u].push_back(make_pair(v,wt));
         graph[v].push_back(make_pair(u,wt));
  }

  int key[n];
  bool MST[n];
  int parent[n];

  for(int i=0 ; i < n ; i++){
          key[i] = INT_MAX;
          MST[i] = false;
          parent[i] = -1;
  }

  key[0] = 0;
  parent[0] = -1;

  for(int c = 0 ; c < n-1 ; c++){
                  
        int mini = INT_MAX, u;
      for(int i = 0 ; i < n ; i++ ){

          if(MST[i] == false && key[i] < mini ){

              mini = key[i], u = i;
          }

      }

      MST[u] = true;  

      for(auto i : graph[u]){
               int a = i.first;
               int b = i.second;

               if(MST[a] == false && b < key[a]){
                     parent[a] = u;
                      key[a] = b;
               }

      }          


  }

  for(int i = 1; i < n ; i++){
          cout<<parent[i]<<"\n";
  }

}