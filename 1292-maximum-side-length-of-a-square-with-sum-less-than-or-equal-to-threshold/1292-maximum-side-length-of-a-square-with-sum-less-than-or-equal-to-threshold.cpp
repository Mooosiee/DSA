class Solution {
public:
    bool squareSide(vector<vector<int>>& grid, int threshold,vector<vector<int>>& prefix_sum,int m,int n,int side){
        for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    int sum = 0;
                    for (int k = i ; k < i + side; k++) {
                        sum += prefix_sum[k][j + side - 1] -
                               (j > 0 ? prefix_sum[k][j - 1] : 0);
                    }
                    if(sum <= threshold){
                        return true;
                    }
                }
            }
        return false;
    }
    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefix_sum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                prefix_sum[i][j] = grid[i][j] + (j > 0 ? prefix_sum[i][j - 1] : 0);
            }
        }
        int l = 1, r = min(m, n);
        int max_side = 0;
        while(l <= r){
            int mid = (l+r) / 2;
            if(squareSide(grid,threshold,prefix_sum,m,n,mid)){
                max_side = max(max_side,mid);
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return max_side;
    }
};