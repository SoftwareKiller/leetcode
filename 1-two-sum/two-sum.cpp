class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            int v = target - nums[i];
            auto it = hash.find(v);
            if (it != hash.end() && it->second != i) {
                return {it->second, i};
            }
            // 放在后面，避免重复元素构成target
            hash[nums[i]] = i;
        }
        return {};
    }
};