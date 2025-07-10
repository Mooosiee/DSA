class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> dis(n + 1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<int> path(n+1);
        for(int i = 1; i <= n;i++){
            path[i] = i;
        }
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[1] = 0;
        pq.push({0,1});
        path[1] = 1;
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                if(dis[node]!=INT_MAX){
                    if(dis[node] + it.second < dis[it.first]){
                        dis[it.first] = dis[node] + it.second;
                        path[it.first] = node;
                        pq.push({dis[it.first],it.first});
                    }
                }
            }
            
        }
        if(dis[n] == INT_MAX) return{-1};
        vector<int> ans;
        int i = n;
        ans.push_back(n);
        while(i!=1){
            ans.push_back(path[i]);
            i = path[i];
        }
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};