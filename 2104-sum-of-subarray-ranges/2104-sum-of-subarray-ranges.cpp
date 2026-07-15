class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            minLeft[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            minRight[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            maxLeft[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            maxRight[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < n; i++) {
            long long minCount = (long long)(i - minLeft[i]) * (minRight[i] - i);
            long long maxCount = (long long)(i - maxLeft[i]) * (maxRight[i] - i);
            minSum += minCount * nums[i];
            maxSum += maxCount * nums[i];
        }

        return maxSum - minSum;
    }
};