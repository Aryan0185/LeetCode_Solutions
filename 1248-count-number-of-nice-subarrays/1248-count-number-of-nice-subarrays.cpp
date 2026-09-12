class Solution {
public:
    int almost(vector<int>& nums,int k){
         int l=0,cnt=0,sum=0;
        for(int r=0;r<nums.size();r++){
          sum+=(nums[r]%2);
          while(sum>k){
            sum-=(nums[l]%2);
            l++;
          }
          cnt+=r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return almost(nums,k)-almost(nums,k-1);
    }
};