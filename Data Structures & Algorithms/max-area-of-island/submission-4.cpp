class Solution {
    int maxArea = 0;

   public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area, int drow[], int dcol[]) {
        int row = grid.size();
        int col = grid[0].size();
        grid[i][j] = 0;
        area++;
        for (int k = 0; k < 4; k++) {
            int newrow = i + drow[k];
            int newcol = j + dcol[k];

            if (newrow >= 0 && newrow < row && newcol >= 0 && newcol < col &&
                grid[newrow][newcol] == 1) {
                dfs(grid, newrow, newcol, area,drow,dcol);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> & grid) {
    int row = grid.size();
    int col = grid[0].size();
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                int area = 0;
                dfs(grid, i, j, area, drow, dcol);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}
}
;
