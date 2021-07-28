#include<bits/stdc++.h>
using namespace std;

bool bipartiteDFS(vector<vector<int>> adj,vector<int> &color,int start){
  if(color[start] == -1)  color[start] = 1;
  for(auto nb : adj[start]){
    if(color[nb] == -1){
      color[nb] =  1 - color[start];
      if(not bipartiteDFS(adj,color,nb))
        return false;
    }
    else if(  color[nb] == color[start])
      return false;
  }
  return true;
}
bool isBipartite(vector<vector<int>> adj,int n){
  vector<int> color(n+1,-1);
  for(int i = 1 ; i <= n+1 ; i++){
    if(color[i] == -1){
      if(not bipartiteDFS(adj,color,i))
        return false;
    }
  }
  return true;
}

vector<vector<int>> adjList(vector<pair<int,int>> input,int n){
  vector<vector<int>> adj(n+1);
  for(auto inp:input){
    int u = inp.first, v = inp.second ; // using ONE based indexing
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return adj;
}

int main(){
  int n,m;
  //  number of vertices -> n, number of edges -> m
  cin >> n >> m;
  vector<pair<int,int>> input(m); // storing input queries in the form of vector of pairs
  for(auto &inp:input){
    int u , v;
    cin >> u >> v; // u and v are connected 
    inp = make_pair(u,v);
  } 
  vector<vector<int>> adj = adjList(input,n);  
  cout << isBipartite(adj,n);
  return 0;
}