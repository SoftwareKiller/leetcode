class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;

        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (curr[1] < intervals[i][0]) {
                ans.push_back(curr);
                curr = intervals[i];
            } else {
                curr[1] = max(intervals[i][1], curr[1]);
            }
        }

        ans.push_back(curr);

        return ans;
    }
};