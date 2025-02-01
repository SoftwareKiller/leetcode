class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        backtrack(digitToLetters, digits, ans, "");
        return ans;
    }

    void backtrack(unordered_map<char, string>& digitToLetters, const string& digits, vector<string>& ans, string curr) {
        int idx = curr.length();
        if (idx == digits.length()) {
            ans.push_back(curr);
            return;
        }

        string letters = digitToLetters[digits[idx]];
        for (char letter : letters) {
            backtrack(digitToLetters, digits, ans, curr + letter);
        }
    }
};