class Solution {
    public int findMin(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }

        int l = 0;
        int r = nums.length - 1;

        if (nums[l] < nums[r]) {
            return nums[l];
        }

        while (l < r) {
            int mid = l + ((r - l) >> 1);

            if (nums[mid] < nums[r]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r--;
            }
        }

        return nums[r];
    }
}