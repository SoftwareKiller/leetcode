class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& v : matrix) {
            int l = 0, r = v.size() - 1;
            if (target < v[l]) {
                return false;
            }

            if (target > v[r]) {
                continue;
            }

            int mid = 0;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if (v[mid] == target) {
                    return true;
                }

                if (v[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};