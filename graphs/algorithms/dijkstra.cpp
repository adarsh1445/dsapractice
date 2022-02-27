#include<bits/stdc++.h>
using namespace std;
int main(){ 
      int n,m,source;
      cout<<"GET NO.OF.NODES AND EDGES"<<"\n";
      cin>>n>>m;
      vector<pair<int,int>> graph[n+1];

      for(int i=0 ; i < m ;i++){
             int u,v,wt;
             cout<<"ENTER VERTICES PATHS AND WEIGHTS"<<"\n";
             cin>>u>>v>>wt;
             graph[u].push_back(make_pair(v,wt));
             graph[v].push_back(make_pair(u,wt));
      }

      priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
      vector<int> dist(n+1,INT_MAX);
      cout<<"ENTER SOURCE VERTICE"<<"\n";
      cin>>source;
      dist[source] = 0;
      pq.push(make_pair(0,source));

      while (!pq.empty())
      {
          cout<<"hi";
          int dis = pq.top().first;
          int prev = pq.top().second;
          pq.pop();

         vector<pair<int,int> > :: iterator it;

          for(auto it : graph[prev] ){

                 int next = it.first;
                 int ndis = it.second;

                 if(dist[next] > dis + ndis){
                    dist[next] = dis + ndis;

                    pq.push(make_pair(dist[next],next));
                 }

          }
       cout<<"The mininum distances from source to each node are : " << "\n"; 
         for(int i = 1; i <= n; i++){
            cout<<dist[i]<<"\n";
         }
      }
      







}