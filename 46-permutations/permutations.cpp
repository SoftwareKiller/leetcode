class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrace(nums, 0, ans);
        return ans;
    }

    void backtrace(vector<int>& nums, int curr, vector<vector<int>>& ans) {
        if (curr == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = curr; i < nums.size(); i++) {
            swap(nums[curr], nums[i]);
            backtrace(nums, curr + 1, ans);
            swap(nums[i], nums[curr]);
        }
    }
};