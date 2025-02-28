class Solution {
public:
    // https://www.bilibili.com/video/BV1zP4y1g72U/?spm_id_from=333.337.search-card.all.click&vd_source=a1ee59002a76dc60bb548da235e16873
    string getPermutation(int n, int k) {
        // 计算每一位的阶乘
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        string ans;
        // 标记数字是否被使用
        vector<bool> used(n + 1);
        for (int i = 0; i < n; i++) {
            int cnt = fact[n - i - 1];
            for (int j = 1; j <= n; j++) {
                if (used[j]) continue;

                // 第k位比当前值的剩余阶乘要大，不满足，减去当前子序列的可能性
                if (k > cnt) k -= cnt;
                else {
                    // 第k位比当前值的剩余阶乘小，k存在于子集中，数字可选
                    used[j] = true;
                    ans += (j + '0');
                    break;
                }
            }
        }
        return ans;
    }
};