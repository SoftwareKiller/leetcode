class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int mid = ((r - l) >> 1) + l;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {
        int i = l, j = mid + 1, curr = 0;
        vector<int> t(r - l + 1);

        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                t[curr] = nums[i];
                i++;
            } else {
                t[curr] = nums[j];
                j++;
            }
            curr++;
        }

        while(i <= mid) {
            t[curr++] = nums[i++];
        }

        while(j <= r) {
            t[curr++] = nums[j++];
        }

        i = l;
        for (int n : t) {
            nums[i++] = n;
        }
    }
};