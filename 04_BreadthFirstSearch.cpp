#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>adj,int n){
  vector<int> path;
  vector<bool> vis(n+1,false);
  for(int i = 1; i <= n ; i++){
    if(not vis[i]){
      queue<int> q;
      q.push(i);
      vis[i] = true;
      while(q.size()){
        int curr = q.front();
        path.push_back(curr);
        q.pop();
        for(auto neighbours:adj[curr]){
          if(not vis[neighbours]){
            q.push(neighbours);
            vis[neighbours] = true;
          }
        }
      }
    }
  }
  return path;
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
  vector<int> travelUsingBFS = bfs(adj,n);
  for(auto i:travelUsingBFS)
    cout << i << " ";
  return 0;
}