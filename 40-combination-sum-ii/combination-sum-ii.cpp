class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        backtrace(candidates, target, 0, comb, ans);
        return ans;
    }

    void backtrace(vector<int>& candidates, int target, int start, vector<int>& comb, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i-1]) {
                continue;
            }

            if ((target - candidates[i]) < 0) {
                continue;
            }
            comb.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i + 1, comb, ans);
            comb.pop_back();
        }
    }
};