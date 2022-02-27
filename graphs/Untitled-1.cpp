#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n;
  cin>>m;
  vector<vector<int>> q;
  int s = 0;
  for(int i = 0 ; i < n ; i ++){
       
       vector<int>k;
         for(int j = 0 ; j < m ; j++){
             int e;
             cin>>e;
             k.push_back(e);
         }
         for(auto l : k){
       s += l;
         }
       q.push_back(k);
  }
       cout<<q.size()<<"\n"<<s;
  }
