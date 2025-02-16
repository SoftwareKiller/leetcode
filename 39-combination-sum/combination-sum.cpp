class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrace(candidates, target, 0, comb, 0, ans);
        return ans;
    }

    void backtrace(vector<int>& candidates, int target, int i, vector<int>& comb, int total, vector<vector<int>>& ans) {
        if (total == target) {
            ans.push_back(comb);
            return;
        }

        if (total > target || i >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[i]);
        backtrace(candidates, target, i, comb, total + candidates[i], ans);
        comb.pop_back();
        backtrace(candidates, target, i + 1, comb, total, ans);
    }
};