class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrace(ans, curr, n, k, 1);
        return ans;
    }

    void backtrace(vector<vector<int>>& ans, vector<int> curr, int n, int k, int i) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (;i <= n; i++) {
            curr.push_back(i);
            backtrace(ans, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};