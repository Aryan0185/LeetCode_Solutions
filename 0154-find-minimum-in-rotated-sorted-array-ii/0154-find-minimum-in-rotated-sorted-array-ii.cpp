class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        if(n==1)return nums[0];
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[low]==nums[mid]&&nums[high]==nums[mid]){
                low=low+1;
                high=high-1;
            }
            else if(nums[high]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return nums[low];
    }
};