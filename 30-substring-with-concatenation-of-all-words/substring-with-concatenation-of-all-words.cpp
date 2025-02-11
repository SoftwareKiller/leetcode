class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.length() == 0 || words.empty()) {
            return ans;
        }
        unordered_map<string, int> hash;
        for (auto& w : words) {
            hash[w]++;
        }

        int len = words[0].size();
        int n = s.length();
        for (int start = 0; start < len; start++) {
            unordered_map<string, int> window;
            int left = start;
            int count = 0;
            for (int r = start; r <= n - len; r += len) {
                string sub = s.substr(r, len);
                auto it = hash.find(sub);
                if (it == hash.end()) {
                    window.clear();
                    count = 0;
                    left = r + len;
                    continue;
                }

                window[sub]++;
                count++;
                while(window[sub] > hash[sub]) {
                    string pop = s.substr(left, len);
                    window[pop]--;
                    count--;
                    left += len;
                }

                if (count == words.size()) {
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};