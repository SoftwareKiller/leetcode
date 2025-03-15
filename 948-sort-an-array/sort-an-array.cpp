class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n/2 - 1; i >= 0; i--) {
            adjust(nums, n, i);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        }

        return nums;
    }

    void adjust(vector<int>& nums, int n, int i) {
        int largest = i;
        int l = i * 2 + 1;
        int r = i * 2 + 2;

        if (l < n && nums[l] > nums[largest]) {
            largest = l;
        }

        if (r < n && nums[r] > nums[largest]) {
            largest = r;
        }

        if (largest != i) {
            swap(nums[i], nums[largest]);
            adjust(nums, n, largest);
        }
    }
};