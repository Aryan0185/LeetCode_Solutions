class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result=nums[0],maxend=nums[0],minend=nums[0];
        if(nums.size()==1)return nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(maxend,minend);
            maxend=max(maxend*nums[i],nums[i]);
             minend=min(minend*nums[i],nums[i]);
             result=max(maxend,result);
        }  
   return result; }
};