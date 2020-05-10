// 200510 pimg
// 46、全排列：根据一个无重复的序列返回其所有可能的全排列
// 回溯

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one(nums.size(), 0);
        dfs(res, {}, nums, one);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int> path, vector<int>& nums, vector<int> & one) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(one[i]) continue;
            one[i] = 1;
            path.push_back(nums[i]);
            dfs(res, path, nums, one);
            path.pop_back();
            one[i] = 0;
        }
    }
};