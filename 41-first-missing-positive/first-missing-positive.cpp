class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 小于等于0的都从数组中移除
        nums.erase(remove_if(nums.begin(), nums.end(), [](int n) { return n <= 0;}), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int n = abs(nums[i]);
            // 等于0的都被移除了，n最小是1，所有在[1,n]区间外的数字才会为正
            if (n <= nums.size() && nums[n-1] > 0) {
                nums[n-1] = -nums[n-1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};