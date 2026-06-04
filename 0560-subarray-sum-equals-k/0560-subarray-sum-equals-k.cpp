class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;  
        mpp[0]=1;
        int prefix=0,cnt=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int need=prefix-k;
            if(mpp.find(need)!=mpp.end())
                cnt+=mpp[need];
                mpp[prefix]++;
        }
        return cnt;
         }
};