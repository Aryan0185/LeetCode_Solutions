class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mono;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty()&&st.top()<nums2[i]){
                mono[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x : nums1){
            ans.push_back(mono.count(x)?mono[x]: -1);
        }
        return ans;
    }
};