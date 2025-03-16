class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> count(100001);
        const int offset = 50000;

        for (int n : nums) {
            if (n < 0) {
                n = -n;
                n = offset - n;
                count[n]++;
            } else {
                count[n+offset]++;
            }
        }

        vector<int> ans(nums.size(), 0);
        int curr = 0;
        for (int i = 0; i < count.size(); i++) {
            for (int j = 0; j < count[i]; j++) {
                if (i < offset) {
                    int n = i - offset;
                    ans[curr++] = n;
                } else {
                    int n = i - offset;
                    ans[curr++] = n;
                }
            }
        }

        return ans;
    }
};