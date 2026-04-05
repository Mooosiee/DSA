class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int fresh_count = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    fresh_count++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 2;
                }
            }
        }
        int mins = -1;
        //top,left,bottom,right
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int qs = q.size();
            while(qs--){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for(int i = 0;i < 4;i++){
                    int r = x+drow[i];
                    int c = y+dcol[i];
                    if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1 && vis[r][c] != 2){
                        q.push({r,c});
                        vis[r][c] = 2;
                        fresh_count--;
                    }
                }

            }
            mins++;
        }
        if(fresh_count) return -1;
        return mins < 0? 0 : mins;
    }
};