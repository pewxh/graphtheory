#include <bits/stdc++.h>
using namespace std;

void topologicalSortHelperDFS(vector<vector<int>> adj,vector<bool> &vis,stack<int> &st,int node){
  vis[node] = true;
  for(auto nb: adj[node])
    if(not vis[nb])
      topologicalSortHelperDFS(adj,vis,st,nb);
  st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> adj,int n){
  stack<int> dfsStack; // can use vector here instead, and reverse it before returning
  vector<int> topologicalOrder;
  vector<bool> vis(n);
  for(int i = 0 ; i <= n ; i++){
    if(not vis[i])
      topologicalSortHelperDFS(adj,vis,dfsStack,i);
  }
  while(dfsStack.size()){
    topologicalOrder.push_back(dfsStack.top());
    dfsStack.pop();
  }
  return topologicalOrder;
}

vector<vector<int>> adjList(vector<pair<int, int>> input, int n)
{
  vector<vector<int>> adj(n + 1);
  for (auto inp : input)
  {
    int u = inp.first, v = inp.second; // using ONE based indexing
    adj[u].push_back(v);
    //adj[v].push_back(u);// graph is directed
  }
  return adj;
}

int main()
{
  int n, m;
  //  number of vertices -> n, number of edges -> m
  cin >> n >> m;
  vector<pair<int, int>> input(m); // storing input queries in the form of vector of pairs
  for (auto &inp : input)
  {
    int u, v;
    cin >> u >> v; // u is directed towards v
    inp = make_pair(u, v);
  }
  vector<vector<int>> adj = adjList(input, n);
  vector<int> topologicalOrder = topologicalSort(adj,n);
  for(auto i : topologicalOrder)
    cout << i << " ";
  return 0;
}