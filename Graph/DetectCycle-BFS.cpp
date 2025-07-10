class Solution {
  private:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfsCheck(neighbor, adj, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[neighbor]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
