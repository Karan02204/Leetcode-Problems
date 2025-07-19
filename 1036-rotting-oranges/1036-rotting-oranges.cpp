class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int minute) {
        int r = grid.size();
        int c = grid[0].size();

        // Out of bounds or empty cell
        if (i < 0 || j < 0 || i >= r || j >= c) return;

        // If the cell is empty or already rotten faster, return
        if (grid[i][j] == 0 || (grid[i][j] > 1 && grid[i][j] < minute)) return;

        grid[i][j] = minute;

        dfs(grid, i + 1, j, minute + 1);
        dfs(grid, i - 1, j, minute + 1);
        dfs(grid, i, j + 1, minute + 1);
        dfs(grid, i, j - 1, minute + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // Start DFS from each rotten orange
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, 2); // Start at minute 2
                }
            }
        }

        int result = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    // Fresh orange remains
                    return -1;
                }
                result = max(result, grid[i][j]);
            }
        }

        return result == 0 ? 0 : result - 2;
    }
};
