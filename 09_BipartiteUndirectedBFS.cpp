#include<bits/stdc++.h>
using namespace std;

bool bipartiteBFS(vector<vector<int>> adj,vector<int> &color,int start){
  queue<int> q;
  q.push(start);
  color[start] = 1;
  while(q.size()){
    int curr = q.front();
    q.pop();
    for(int neighbour:adj[curr]){
      if(color[neighbour] == -1){
        q.push(neighbour);
        color[neighbour] = not color[curr]; 
      }
      else if(color[neighbour] == color[curr])
        return false;
    }
  }
  return true;
}
bool isBipartite(vector<vector<int>> adj,int n){
  vector<int> color(n+1,-1);
  for(int i = 1 ; i <= n+1 ; i++){
    if(color[i] == -1){
      if(not bipartiteBFS(adj,color,i))
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