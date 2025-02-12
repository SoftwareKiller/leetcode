class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2; 
        
        // 从后向前找第一个升序数字
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            // 从后向前找第一个比升序数字大的数字
            while(nums[j] <= nums[i]) {
                j--;
            }
            // 把大数交换到低位
            swap(nums[i], nums[j]);
        }

        // 对后续数组做逆序，小数在高位，大数在低位
        reverse(nums.begin() + i + 1, nums.end());
    }
};