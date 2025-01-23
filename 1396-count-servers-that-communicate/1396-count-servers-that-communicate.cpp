class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        bool rows[250];
        int m = grid.size(), n = grid[0].size();
        for (int r = 0; r < m; r++){
            int count = accumulate(grid[r].begin(), grid[r].end(), 0);
            if (count > 1){
                res += count;
                rows[r] = true;
            }
        }
        for (int c = 0; c < n; c++){
            int counted = 0, total = 0;
            for (int r = 0; r < m; r++){
                if (grid[r][c] == 1){
                    total++;
                    if (rows[r]) counted++;
                }
            }
            if (total > 1) res += total - counted;
        }
        return res;
    }
};