#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList(vector<pair<int,int>> input,int n){
  vector<vector<int>> adj(n+1);
  for(auto inp:input){
    int u = inp.first, v = inp.second ; // using ONE based indexing
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  return adj;
}

void printAdjList(vector<vector<int>> adj){
  for(int i=1;i<adj.size();i++){
    cout << i << " is directed towards ";
    for(auto j:adj[i])
      cout << j << " ";
    cout << endl;
  }
}

int main(){
  int n,m;
  //  number of vertices -> n, number of edges -> m
  cin >> n >> m;
  vector<pair<int,int>> input(m,pair<int,int>({0,0})); // storing input queries in the form of vector of pairs
  for(auto &inp:input){
    int u , v;
    cin >> u >> v; // u and v are connected 
    inp = make_pair(u,v);
  } 
  vector<vector<int>> graphAsAdjacencyList = adjList(input,n);  
  cout << "* Graph in the form of Adjacency List \n";
  printAdjList(graphAsAdjacencyList);
  cout << "\n";
  return 0;
}
