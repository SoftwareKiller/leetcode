class Solution {
    public int[] sortArray(int[] nums) {
        int n = nums.length;

        for (int i = n/2 - 1; i >= 0; i--) {
            adjust(nums, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(nums, 0, i);
            adjust(nums, i, 0);
        }

        return nums;
    }

    public void adjust(int[] nums, int n, int i) {
        int largest = i;
        int l = i * 2 + 1;
        int r = i * 2 + 2;

        if (l < n && nums[l] > nums[largest]) {
            largest = l;
        }

        if (r < n && nums[r] > nums[largest]) {
            largest = r;
        }

        if (i != largest) {
            swap(nums, i, largest);
            adjust(nums, n, largest);
        }
    }

    public void swap(int[] nums, int l, int r) {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
}