#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjMatrix(vector<pair<int,int>> input,int n){
  vector<vector<int>> adj(n,vector<int>(n,0)); // creates a n*n matrix and fills it with zeroes.
  for(auto inp:input){
    int u = inp.first - 1, v = inp.second - 1; // using ZERO based indexing
    adj[u][v] = adj[v][u] = 1;
  }
  return adj;
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

void printAdjMatrix(vector<vector<int>> adj){
  for(auto r:adj){
    for(auto c:r)
      cout << c;
    cout << "\n";
  }
}

void printAdjList(vector<vector<int>> adj){
  for(int i=1;i<adj.size();i++){
    cout << i << " is connected with ";
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

  vector<vector<int>> graphAsAdjacencyMatrix = adjMatrix(input,n);  
  cout << "* Graph in the form of Adjacency Matrix \n";
  printAdjMatrix(graphAsAdjacencyMatrix);
  cout << "\n";

  vector<vector<int>> graphAsAdjacencyList = adjList(input,n);  
  cout << "* Graph in the form of Adjacency List \n";
  printAdjList(graphAsAdjacencyList);
  cout << "\n";
  return 0;
}

/*
NOTES:
  Comparision between the above 2 methods:

          Operations          \       Adj Matrix        \       Adj List         \
  
  * Space Complexity          \          O(n^2)         \          O(n+m)        \
  * Finding Adj of a node     \           O(n)          \           O(1)         \
  * Check if 2 nodes are adj  \           O(1)          \           O(n)         \

*/