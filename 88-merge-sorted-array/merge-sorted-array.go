func merge(nums1 []int, m int, nums2 []int, n int)  {
    i := m + n - 1
    m--
    n--
    for i >= 0 && (m >= 0 || n >= 0) {
        if m < 0 {
            nums1[i] = nums2[n]
            i--
            n--
            continue
        }

        if n < 0 {
            nums1[i] = nums1[m]
            i--
            m--
            continue
        }

        if nums1[m] > nums2[n] {
            nums1[i] = nums1[m]
            m--
        } else {
            nums1[i] = nums2[n]
            n--
        }
        i--
    }
}