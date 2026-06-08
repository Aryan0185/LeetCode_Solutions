class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       for(int i=0;i<n;i++){
           nums1[m+i]=nums2[i];
       }
           int total=m+n;
           int gap=(total+1)/2;
        while(gap>0){
            int i=0,j=gap;
            while(j<total){
            if(nums1[i]>nums1[j])
            swap(nums1[i],nums1[j]);
            i++;
            j++;}
            if(gap==1)break;
            gap=(gap+1)/2;
        }
    }
};