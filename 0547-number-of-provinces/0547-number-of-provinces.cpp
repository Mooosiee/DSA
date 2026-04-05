class Solution {
public:
    void bfs(vector<vector<int>>& isConnected,int i,vector<int>& visited,int n){
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int j = 0;j < n;j++){
                if(isConnected[node][j] == 1 && !visited[j]){
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n + 1 ,0);
        for(int i = 0; i < n;i++){
                if(!visited[i]){
                    bfs(isConnected,i,visited,n);
                    provinces++;
                }
            
        }
        return provinces;
    }
};