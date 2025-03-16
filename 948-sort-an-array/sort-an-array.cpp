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

        vector<int> ans;
        for (int i = 0; i < count.size(); i++) {
            for (int j = 0; j < count[i]; j++) {
                if (i < offset) {
                    int n = i - offset;
                    ans.push_back(n);
                } else {
                    int n = i - offset;
                    ans.push_back(n);
                }
            }
        }

        return ans;
    }
};