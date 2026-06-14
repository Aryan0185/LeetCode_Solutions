class Solution {
public:
   int fun(vector<int>&nums,int div){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        //Formula: ceil(a/b) = (a + b - 1) / b
        sum+=(nums[i]+div-1)/div;
    }
    return sum;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int sam=fun(nums,mid);
            if(sam<=threshold)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};