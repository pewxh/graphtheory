#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adjListWeighted(vector<vector<int>> input,int n){
  vector<vector<pair<int,int>>> adj(n+1);
  for(auto inp:input){
    int u = inp[0], v = inp[1] , w = inp[2]; // using ONE based indexing
    adj[u].push_back(make_pair(v,w));
    // adj[v].push_back(make_pair(u,w)); // uncomment this line, if the graph is undirectional
  }
  return adj;
}

void printAdjListWeighted(vector<vector<pair<int,int>>> adj){
  for(int i=1;i<adj.size();i++){
    for(auto j:adj[i])
      cout << i << " is directed towards " << j.first << " having weight " << j.second << "\n";
  }
}

int main(){
  int n,m;
  //  number of vertices -> n, number of edges -> m
  cin >> n >> m;
  vector<vector<int>> input(m); // storing input queries in the form of vector of vector
  for(auto &inp:input){
    int u , v, w;
    cin >> u >> v >> w; // u is connected to v having weight w.
    inp = {u,v,w};
  } 
  vector<vector<pair<int,int>>> weightedGraph = adjListWeighted(input,n);  
  cout << "* Weighted Graph \n";
  printAdjListWeighted(weightedGraph);
  cout << "\n";
  return 0;
}
