class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(!st.empty()&&st.top()!=nums[i]){
                st.pop();
            }else{
                st.push(nums[i]);
            }
        }
        return st.top();
    }
};