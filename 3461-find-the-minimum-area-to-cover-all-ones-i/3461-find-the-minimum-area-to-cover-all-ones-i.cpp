class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        int minRow = rows-1;
        int maxRow = 0;
        int minCol = cols-1;
        int maxCol = 0;
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(grid[row][col] == 1) {
                    minRow = min(minRow, row);
                    maxRow = max(maxRow, row);
                    minCol = min(minCol, col);
                    maxCol = max(maxCol, col);
                }
            }
        }

        int width = maxCol-minCol+1;
        int height = maxRow-minRow+1;

        return width*height;
    }
};