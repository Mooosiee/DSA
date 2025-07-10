/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(n == 1 && grid[0][0] == 0) return 1;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        //{{row,col},len} {row,col} = node
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        vis[0][0] = 1;
        int dir[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        while (!q.empty()) {
            auto node = q.front().first;
            int x = node.first;
            int y = node.second;
            int len = q.front().second;
            q.pop();
            for (auto it : dir) {
                int newx = it[0] + x;
                int newy = it[1] + y;
                if (newx >= 0 && newy >= 0 && newx < n && newy < n &&
                    (grid[newx][newy] == 0) && !vis[newx][newy]) {

                    q.push({{newx,newy}, len + 1});
                    vis[newx][newy] = 1;
                    if(newx == n-1 && newy == n-1){
                        return len + 1;
                    }
                }
            }
        }
       
    
    return -1;
}
}
;