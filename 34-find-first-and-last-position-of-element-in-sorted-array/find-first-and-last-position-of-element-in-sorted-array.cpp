class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while(l <= r) {
            mid = (r - l) / 2 + l;
            if (nums[mid] == target) {
                int begin = mid;
                int end = mid;
                while (begin >= 0 && nums[begin] == target) {
                    begin--;
                }
                while (end < nums.size() && nums[end] == target) {
                    end++;
                }
                ans[0] = begin + 1, ans[1] = end - 1;
                return ans;
            }

            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};