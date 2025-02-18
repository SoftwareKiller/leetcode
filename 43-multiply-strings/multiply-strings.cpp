class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.length(), n = num2.length();
        vector<int> mul(m+n, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int num = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j, p2 = i + j + 1;
                int sum = num + mul[p2];
                mul[p2] = sum % 10;
                mul[p1] += sum / 10;
            }
        }

        string ans;
        for (int it : mul) {
            if (it != 0 || !ans.empty()) {
                ans.push_back(it + '0');
            }
        }
        return ans;
    }
};