class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closeNum = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while( j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int temp = closeNum;
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    closeNum = min(closeNum, target - sum);
                    j++;
                } else {
                    closeNum = min(closeNum, sum - target);
                    k--;
                }
                if (temp != closeNum) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};