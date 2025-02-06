class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, "", n, ans);
        return ans;
    }

    void dfs(int l, int r, string p, int n, vector<string>& ans) {
        if (l == r && l + r == n * 2) {
            ans.push_back(p);
            return;
        }

        if (l < n) {
            dfs(l + 1, r, p + "(", n, ans);
        }

        if (r < l) {
            dfs(l, r + 1, p + ")", n, ans);
        }
    }
};