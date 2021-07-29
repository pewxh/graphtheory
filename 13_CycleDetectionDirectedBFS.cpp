#include <bits/stdc++.h>
using namespace std;

//      Kahn's Algorithm
vector<int> topologicalSort(vector<vector<int>> adj,int n){
  vector<int> topologicalOrder;
  queue<int> q;
  vector<int> inDeg(n+1,0); // stores indegree of each node
  for(int i = 0 ; i<= n ;i++){
    for(auto nb:adj[i])
      inDeg[nb]++;
  }
  for(int i = 0 ; i <= n ; i++)
      if(not inDeg[i])
        q.push(i);
  // push all the nodes having zero indegree to the queue
  while(q.size()){
    int node = q.front();
    topologicalOrder.push_back(node);
    q.pop();

    for(auto nb : adj[node]){
      inDeg[nb]--;
      if(not inDeg[nb])
        q.push(nb);
    }
  }
  return topologicalOrder;
}

bool isCycleDirectedBFS(vector<vector<int>> adj,int n){
  vector<int> topo = topologicalSort(adj,n);
  return topo.size() == n;
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
  cout << isCycleDirectedBFS(adj, n);
  return 0;
}