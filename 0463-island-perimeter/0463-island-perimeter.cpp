class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int& sum) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1;
        if (i - 1 < 0 || grid[i - 1][j] == 0){
            sum += 1;
        } 
        if (j + 1 >= c || grid[i][j + 1] == 0){
            sum += 1;
        }
        if (i + 1 >= r || grid[i + 1][j] == 0){
            sum += 1;
        }
        if (j - 1 < 0 || grid[i][j - 1] == 0) {
            sum += 1;
        }

        dfs(grid, i, j + 1, r, c, sum);
        dfs(grid, i - 1, j, r, c, sum);
        dfs(grid, i, j - 1, r, c, sum);
        dfs(grid, i + 1, j, r, c, sum);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int sum = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, r, c, sum);
                }
            }
        }

        return sum;
    }
};