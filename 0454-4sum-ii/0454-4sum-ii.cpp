class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                mpp[nums1[i]+nums2[j]]++;
            }
        }
        int cnt=0;
        for(int k=0;k<nums3.size();k++){
            for(int l=0;l<nums4.size();l++){
                int target=-(nums3[k]+nums4[l]);
                if(mpp.count(target))cnt+=mpp[target];
            }
        }
        return cnt;
    }
};