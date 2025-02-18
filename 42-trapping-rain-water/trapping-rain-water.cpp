class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int l = 0, r = height.size() - 1;
        int lMax = height[l], rMax = height[r];
        while(l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                water += lMax - height[l];
            } else {
                r--;
                rMax = max(rMax, height[r]);
                water += rMax - height[r];
            }
        }
        return water;
    }
};