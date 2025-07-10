/*NOTE: In topological sorting, node u will always appear before node v 
if there is a directed edge from node u towards node v(u -> v).
It Exists only in DAG(Directed Acyclic Graph)
DAG:
>Directed: All edges have a direction (from one node to another).

>Acyclic: No cycles — you can’t start at a node and follow a path that leads back to it.

>Can be disconnected: DAGs may have multiple components.*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int s,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st){
    visited[s] = 1;
    for(int i = 0; i < adj[s].size(); i++){
        if(adj[s][i] == 1 && !visited[adj[s][i]]){
            dfs(i,adj,visited,st);
        }
    }
    st.push(s);
}
int main(){
    int v;
    cin >> v;
    vector<vector<int>> adj(v,vector<int>(v,0));
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            cin >> adj[i][j];
        }
    }
    vector<int> visited(v,0);
    stack<int> st;
    for(int i = 0 ; i < v;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}