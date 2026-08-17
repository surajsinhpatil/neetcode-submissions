class Solution {
    int maxArea = 0;

   public:
    int dfs(vector<vector<int>>& grid, int i, int j, int area) {
        int row = grid.size();
        int col = grid[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        area=1;

        area+=dfs(grid, i - 1, j, area);
        area+=dfs(grid, i, j - 1, area);
        area+=dfs(grid, i + 1, j, area);
        area+=dfs(grid, i, j + 1, area);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int area=dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
            
        }
        return maxArea;
    }
};
