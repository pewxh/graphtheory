#include<bits/stdc++.h>
using namespace std;

bool cycleCheck(vector<vector<int>> adj,int curr,vector<bool> &vis){
  queue<pair<int,int>> q;
  q.push(make_pair(curr,-1)); // assuming '-1' as the previous/parent node
  vis[curr] = true;
  while(q.size()){
    int curr = q.front().first;
    int prev = q.front().second;
    q.pop();
    for(auto neighbour:adj[curr]){
      if(not vis[neighbour]){
        q.push(make_pair(neighbour,curr));
        vis[neighbour] = true;
      }
      else if(neighbour != prev)
        return true; // cycle found
    }
  }
  return false;
}

bool isCycleBFS(vector<vector<int>>adj,int n){
  vector<bool> vis(n+1);
  for(int i = 1; i<=n;i++)
    if(not vis[i])
      if (cycleCheck(adj,i,vis)) return true;
  return false;
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
  cout << isCycleBFS(adj,n);
  return 0;
}