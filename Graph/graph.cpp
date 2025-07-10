#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    vector<vector<int>> adj;
public:
    graph(int v){
        this -> v = v;
        adj.resize(v,vector<int>(v,0));
    }
    void addedge(int u,int v){
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    void printmatrix(){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int s,vector<int> &visited){
        visited[s] = 1;
        cout << s << " ";
        for(int i = 0; i < v; i++){
            if(adj[s][i] == 1 && !visited[i]){
                dfs(i,visited);
            }
        }
    }
    void bfs(int s,vector<int> &visited){
        queue<int> q;
        visited[s] = 1;
        q.push(s);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(int i= 0; i < v;i++){
                if(adj[node][i] == 1  && !visited[i]){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        } 
    }

};
int main(){
    int v = 5;
    graph g(v);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(2,4);
    g.printmatrix();
    vector<int> visited(v,0);
    cout << "BFS Traversal: ";
    g.bfs(0,visited);
    cout << endl;
}
