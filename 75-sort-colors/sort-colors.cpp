class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3];

        for (int i : nums) {
            colors[i]++;
        }

        int begin = 0;
        for (int color = 0; color < 3; color++) {
            for (int i = begin; i < begin + colors[color]; i++) {
                nums[i] = color;
            }
            begin += colors[color];
        }
    }
};