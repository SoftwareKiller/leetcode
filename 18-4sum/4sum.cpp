class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        for (int i = 0; i < n - 3; i++) {
            for(int j = i+1; j < n - 2; j++) {
                int64_t subTarget = (int64_t)target - (int64_t)nums[i] - (int64_t)nums[j];
                int low = j + 1, high = n - 1;
                while(low < high) {
                    if(nums[low] + nums[high] < subTarget) {
                        low++;
                    } else if(nums[low] + nums[high] > subTarget) {
                        high--;
                    } else {
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++, high--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto item : set) {
            ans.push_back(item);
        }
        return ans;
    }
};