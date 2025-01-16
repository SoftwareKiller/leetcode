class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;

        // 查找中位数
        for(int count = 0; count <= (m + n) / 2; ++count) {
            // 如果两数组长度为偶数位，则保留2位
            m2 = m1;
            if ( i < m && j < n) {
                if (nums1[i] > nums2[j]) {
                    m1 = nums2[j++];
                } else {
                    m1 = nums1[i++];
                }
            } else if ( i < m) {
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
        }

        if ((m + n) % 2 == 1) {
            return static_cast<double>(m1);
        }
        return (static_cast<double>(m1) + static_cast<double>(m2)) / 2.0;
    }
};