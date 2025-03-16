class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);

        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            while(st.size() > 1 && heights[st.top()] > heights[i]) {
                int t = st.top();
                st.pop();
                int weight = i - st.top() - 1;
                int curr = heights[t] * weight;
                ans = max(ans, curr);
            }

            st.push(i);
        }

        while(st.size() > 1) {
            int t = st.top();
            st.pop();
            int weight = heights.size() - st.top() - 1;
            int curr = heights[t] * weight;
            ans = max(ans, curr);
        }

        return ans;
    }
};