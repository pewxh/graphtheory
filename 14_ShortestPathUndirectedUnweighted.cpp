#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathBFS(vector<vector<int>> adj,int n,int src){
  vector<int> dist(n+1,INT_MAX);
  queue<int> q;
  dist[src] = 0;
  q.push(src);
  while(q.size()){
    int node = q.front();
    q.pop();
    for(auto nb : adj[node]){
      if(dist[nb] > dist[node] + 1){
        q.push(nb);
        dist[nb] = dist[node] + 1;
      }
    }
  }
  return dist;
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
  int src;
  cin >> src;
  auto dist = shortestPathBFS(adj, n,src);
  for(int i = 1 ; i <= n ; i++)
    cout << src << " -> " << i << " " << dist[i] << endl; 
  return 0;
}