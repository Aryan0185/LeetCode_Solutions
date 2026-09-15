class Solution {
public:
    int  atmost(vector<int>&nums,int k){
        if(k<0)return 0;
        unordered_map<int,int>mpp;
        int cnt=0,left=0;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0)mpp.erase(nums[left]);
                left++;
            }
            cnt+=right-left+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};