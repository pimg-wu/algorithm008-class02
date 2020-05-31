//200531 pimg
//64、最小路径和：在二维数组中找出一条和为最小的从左上角到右下角的路径和

//动态规划（DP）
//DP方程：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];   
//（需注意左边界和上边界的问题）

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(i == 0 && j == 0) continue;
                else if(i == 0) grid[i][j] = grid[i][j-1] + grid[i][j];
                else if(j == 0) grid[i][j] = grid[i-1][j] + grid[i][j];
                else grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};