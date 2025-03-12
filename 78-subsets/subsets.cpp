class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        for (int i = 0; i <= nums.size(); i++) {
            backtrace(nums, ans, curr, i, 0);
        }
        return ans;
    }

    void backtrace(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int limit, int start) {
        if (curr.size() == limit) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrace(nums, ans, curr, limit, i + 1);
            curr.pop_back();
        }
    }
};