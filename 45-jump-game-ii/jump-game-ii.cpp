class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int end = nums.size() - 1;
        int distance = 0;
        int curr = 0;
        while(distance < end) {
            int m = 0;
            for(int i = curr; i <= distance; i++) {
                m = max(m, i + nums[i]);
            }
            curr = distance + 1;
            distance = m;
            count++;
        }
        return count;
    }
};