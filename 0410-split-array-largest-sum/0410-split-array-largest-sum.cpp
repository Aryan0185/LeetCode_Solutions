class Solution {
public:
     int splitpage(vector<int>& nums,int pages){
        int student=1;
        long long pagestudent=0;
        for(int i=0;i<nums.size();i++){
            if(pagestudent+nums[i]<=pages){
                pagestudent += nums[i];
            }else {
                student++;
                pagestudent=nums[i];
            }
        }
        return student;
     }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
      int low=*max_element(nums.begin(),nums.end());
      int high=accumulate(nums.begin(),nums.end(),0);  
      while(low<=high){
        int mid=low+(high-low)/2;
        int split=splitpage(nums,mid);
        if(split>k)low=mid+1;
        else high=mid-1;
      }
      return low;
    }
};