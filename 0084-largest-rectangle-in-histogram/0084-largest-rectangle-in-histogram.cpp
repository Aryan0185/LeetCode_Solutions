class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        vector<int> Left(n),Right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            Left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >=heights[i]) st.pop();
            Right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long area=0;
        for (int i = 0; i < n; i++) {
            long long width=Right[i]-Left[i]-1;
            area=max(area,width*heights[i]);
        }

        return area; 
    }
};