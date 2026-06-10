class Solution {
public:
    int first_pos(vector<int>& nums,int target){
          int low=0,high=nums.size()-1;
          int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {ans=mid;
            high=mid-1;}
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    int last_pos(vector<int> & nums,int target){
          int low=0,high=nums.size()-1;
          int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {ans=mid;
             low=mid+1;}
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    return {first_pos(nums,target),last_pos(nums,target)};     }
};