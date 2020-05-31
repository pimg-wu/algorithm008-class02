//200531 pimg
//120、三角形最小路径和：从一个三角形中找出自顶向下的最小路径和

//动态规划（DP）的题解思路：找重复性（子问题）、定义状态数组、DP方程（递推公式）

//DP方程：problem(i, j) = min(sub(i+1, j), sub(i+1, j+1)) + a[i, j];


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};