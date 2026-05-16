// Kruskal’s Algorithm is almost always implemented using the Disjoint Set (also called Union Find / DSU) data structure.
// Why? Kruskal’s algorithm works like this:
// Sort all edges by weight.
// Keep picking the smallest edge.
// Add the edge only if it does not form a cycle.
// The hard part is:
// “How do we quickly know whether adding an edge creates a cycle?”
// That’s exactly what DSU helps with.
// Suppose we have an edge:
// (u,v)
// Before adding it:
// If u and v already belong to the same component, adding the edge creates a cycle → skip it.
// Otherwise, add the edge and merge the two components.
// DSU provides these operations efficiently:
// find(x) → tells which component/node-group x belongs to
// union(a,b) → merges two components
// The reason DSU is preferred:
// Very fast
// Detects cycles efficiently
// Makes Kruskal run in roughly:
// O(ElogE)
// Sorting dominates the complexity.
// Without DSU, cycle checking would become expensive.
#include <iostream>
#include <vector>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;

public:
  DisjointSet(int n){
    rank.resize(n+1,0);
    //this parent array might only contain an intermediate parent and not the ultimate parent, 
    //so we will be using findUPar function to find the ultimate parent of a node. always! 
    parent.resize(n+1);
    size.resize(n+1);
    for(int i = 0;i <= n;i++){
        parent[i] = i;
        size[i] = 1;
    }
  }
  int findUPar(int node){
    if(node == parent[node]){
        return node;
    }
    // the below line is path compression
    return parent[node] = findUPar(parent[node]);
    // if i was not doing path compression then the line would look like : return findUPar(parent[node]);
  }
  void UnionByRank(int u,int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if(ulp_u == ulp_v){
        return;
    }
    if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
         parent[ulp_v] = ulp_u;
    }
    else{
         parent[ulp_v] = ulp_u;
         rank[ulp_u]++;
    }
  }
  void UnionBySize(int u,int v){
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if(ulp_u == ulp_v){
        return;
    }
    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else{
        parent[ulp_v] = ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
  }
};
int main(){

}
