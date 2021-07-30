#include <bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgo(vector<vector<pair<int,int>>>adj,int n){
  vector<int> topo;
  queue<int> q;
  vector<int> inDeg(n+1,0);
  for(int i = 1; i <= n ; i++){
    for(auto it : adj[i]){
      inDeg[it.first]++;
    }
  }
  for(int i = 1 ; i <= n ; i++)
    if(not inDeg[i])
      q.push(i);
  while(q.size()){
    int node = q.front();
    topo.push_back(node);
    q.pop();

    for(auto nb : adj[node])
      if( (--inDeg[nb.first]) == 0)
        q.push(nb.first);
  }
  return topo;
}

vector<int> shortestPath(vector<vector<pair<int,int>>> adj, int n, int src)
{
  vector<int> dist(n + 1, INT_MAX);
  vector<bool> vis(n+1,false);
  vector<int> topo = kahnsAlgo(adj,n);
  dist[src] = 0;
  for(auto node:topo){
    if(dist[node] != INT_MAX){
      for(auto nb:adj[node]){
        dist[nb.first] = min(dist[nb.first],dist[node] + nb.second);
      }
    }
  }
  return dist;
}

vector<vector<pair<int, int>>> adjListWeighted(vector<vector<int>> input, int n)
{
  vector<vector<pair<int, int>>> adj(n + 1);
  for (auto inp : input)
  {
    int u = inp[0], v = inp[1], w = inp[2]; // using ONE based indexing
    adj[u].push_back(make_pair(v, w));
  }
  return adj;
}

int main()
{
  int n, m;
  //  number of vertices -> n, number of edges -> m
  cin >> n >> m;
  vector<vector<int>> input(m); // storing input queries in the form of vector of vector
  for (auto &inp : input)
  {
    int u, v, w;
    cin >> u >> v >> w; // u is connected to v having weight w.
    inp = {u, v, w};
  }
  vector<vector<pair<int, int>>> adj = adjListWeighted(input, n);
  int src;  cin >> src;
  auto dist = shortestPath(adj, n, src);
  for (int i = 1; i <= n; i++)
    cout << src << " -> " << i << " " << dist[i] << endl;
  return 0;
}