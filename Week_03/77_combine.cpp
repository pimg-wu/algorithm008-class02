// 200510 pimg
// 77、组合：根据两个整数n、k返回 1...n中所有可能的k个数组合
// 回溯+剪枝

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n) return res;
        vector<int> one;
        dfs(n, k, 1, one);
        return res;
    }
    void dfs(int n, int k, int l, vector<int>& one) {
        if(one.size() == k) {
            res.push_back(one);
            return;
        }
        for(int i = l; i <= n - (k - one.size()) + 1; ++i) {
            one.push_back(i);
            dfs(n, k, i + 1, one);
            one.pop_back();
        }
    }
};