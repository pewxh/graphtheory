#include <bits/stdc++.h>
using namespace std;


bool cycleCheck(vector<vector<int>> adj, int curr, int prev, vector<bool> &vis)
{
  vis[curr] = true;
  for (auto neighbour : adj[curr])
  {
    if (not vis[neighbour]){
      if (cycleCheck(adj, neighbour, curr, vis))
        return true;
    }
    else if (neighbour != prev)
      return true;
  }
  return false;
}

bool isCycleDFS(vector<vector<int>> adj, int n)
{
  vector<bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (not vis[i])
      if (cycleCheck(adj,i,-1,vis))
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
    adj[v].push_back(u);
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
    cin >> u >> v; // u and v are connected
    inp = make_pair(u, v);
  }
  vector<vector<int>> adj = adjList(input, n);
  cout << isCycleDFS(adj, n);
  return 0;
}