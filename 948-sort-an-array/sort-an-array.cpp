class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int r = nums.size() - 1;
        srand(time(nullptr));
        quicksort(nums, 0, r);
        return nums;
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int i = partition(nums, l, r);

        quicksort(nums, l, i - 1);
        quicksort(nums, i + 1, r);
    }

    int midNum(vector<int>& nums, int l, int r) {
        int mid = ((r - l) >> 1) + l;
        if (nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
            return mid;
        }

        if (nums[mid] <= nums[l] && nums[l] <= nums[r]) {
            return l;
        }

        return r;
    }

    int partition(vector<int>& nums, int l, int r) {
        int i = l, j = r;
        int mid = midNum(nums, l, r);
        swap(nums[l], nums[mid]);
        while(i < j) {
            // 结束后j右边的数都比nums[l]大
            // while(i < j && nums[j] >= nums[l]) j--;
            while(i < j && nums[j] >= nums[l]) j--;
            // 结束后i左边的数都比nums[l]小
            //while(i < j && nums[i] <= nums[l]) i++;
            while(i < j && nums[i] <= nums[l]) i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        return i;
    }
};