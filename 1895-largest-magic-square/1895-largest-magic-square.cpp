class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowsum(m, vector<int>(n, 0));
        vector<vector<int>> colsum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowsum[i][j] = grid[i][j] + (j > 0 ? rowsum[i][j - 1] : 0);
            }
        }

        for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
        colsum[i][j] = grid[i][j] + (i > 0 ? colsum[i - 1][j] : 0);
    }
}

        for (int side = min(m, n); side >= 2; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {
                    int targetSum = rowsum[i][j + side - 1] -
                                    (j > 0 ? rowsum[i][j - 1] : 0);
                    // check all sums;
                    bool rows;
                    for (int k = i + 1; k < i + side; k++) {
                        int sum = rowsum[k][j + side - 1] -
                                  (j > 0 ? rowsum[k][j - 1] : 0);
                        if (sum != targetSum) {
                            rows = false;
                            break;
                        }
                        rows = true;
                    }
                    if (!rows)
                        continue;
                    bool cols;
                    for (int k = j; k < j + side; k++) {
                        int sum = colsum[i + side - 1][k] -
                                  (i > 0 ? colsum[i - 1][k] : 0);
                        if (sum != targetSum) {
                            cols = false;
                            break;
                        }
                        cols = true;
                    }
                    if (!cols)
                        continue;
                    int diag1 = 0, diag2 = 0;
                    for (int k = 0; k < side; k++) {
                        diag1 += grid[i + k][j + k];
                        diag2 += grid[i + k][j + side - 1 - k];
                    }
                    if (diag1 == targetSum && diag2 == targetSum) {
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};