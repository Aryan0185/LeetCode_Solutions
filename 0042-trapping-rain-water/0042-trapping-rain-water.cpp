class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int>st;
        long long sum=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[st.top()]<height[i]){
                int bottom=st.top();
                st.pop();
                if(st.empty()) break;
                int left=st.top();
                int bounded=min(height[left],height[i])-height[bottom];
                int width=i-left-1;
                sum+=(long long)bounded*width;
            }
            st.push(i);
        }
        return sum;
    }
};