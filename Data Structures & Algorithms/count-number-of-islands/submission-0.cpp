class Solution {
   public:
    void dfs(vector<vector<char>>& matrix, int row, int col) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (row >= 0 && row < n && col >= 0 && col < m && matrix[row][col] != '0') {
        matrix[row][col] = '0';
            dfs(matrix, row - 1, col);
            dfs(matrix, row, col + 1);
            dfs(matrix, row + 1, col);
            dfs(matrix, row, col - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // int deltarow[]= {-1,0,1,0};
        // int deltacol[]= {0,1,0,-1};
        vector<vector<char>> matrix = grid;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    ans++;
                    dfs(matrix, i, j);
                }
            }
        }

        return ans;
    }
};
