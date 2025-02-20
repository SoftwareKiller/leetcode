class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        backtrace(nums, st, 0, ans);
        return ans;
    }

    void backtrace(vector<int>& nums, set<vector<int>>& st, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            auto it = st.find(nums);
            if (it != st.end()) {
                return;
            }
            st.insert(nums);
            ans.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrace(nums, st, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }
};