class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j) {
        
        int m = grid.size();
        int n = grid[0].size();

        // Out of boundary
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Already water
        if(grid[i][j] == 0)
            return;

        // Mark as visited
        grid[i][j] = 0;

        // 4 directions
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Boundary rows
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1)
                dfs(grid, 0, j);

            if(grid[m-1][j] == 1)
                dfs(grid, m-1, j);
        }

        // Boundary columns
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1)
                dfs(grid, i, 0);

            if(grid[i][n-1] == 1)
                dfs(grid, i, n-1);
        }

        // Count remaining land cells
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};