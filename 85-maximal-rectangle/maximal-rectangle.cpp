class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int maxArea = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height(cols, 0);

        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            int currArea = maxRectangle(height);
            if (currArea > maxArea) {
                maxArea = currArea;
            }
        }
        return maxArea;
    }

    int maxRectangle(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        st.push(-1);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while(st.size() > 1 && height[i] < height[st.top()]) {
                int t = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int area = height[t] * w;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        while (st.size() > 1) {
            int t = st.top();
            st.pop();
            int w = n - st.top() - 1;
            int area = height[t] * w;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};