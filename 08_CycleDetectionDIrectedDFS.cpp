#include <bits/stdc++.h>
using namespace std;


bool cycleCheck(vector<vector<int>> adj, int curr, vector<bool> &vis,vector<bool> &currVis)
{
  vis[curr] = true;
  currVis[curr] = true;
  for (auto neighbour : adj[curr])
  {
    if (not vis[neighbour]){
      if (cycleCheck(adj, neighbour, vis,currVis))
        return true;
    }
    else if (currVis[neighbour])
      return true;
  }
  currVis[curr] = false;
  return false;
}

bool isCycleDirectedDFS(vector<vector<int>> adj, int n)
{
  vector<bool> vis(n + 1, false);
  vector<bool> currVis(n+1,false); // keeps track of visited nodes in current call stack
  for (int i = 1; i <= n; i++)
    if (not vis[i])
      if (cycleCheck(adj,i,vis,currVis))
        return true;
  return false;
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
  cout << isCycleDirectedDFS(adj, n);
  return 0;
}