class Solution {
public:
int fun(vector<int>& bloomDay,int maxd,int k){
             int cnt=0,bouquets=0;
             for(int j=0;j<bloomDay.size();j++){
                if(bloomDay[j]<=maxd){
                    cnt++;
                    if(cnt==k){
                        bouquets++;
                        cnt=0;
                    }
                }
                else {
                cnt=0;
                }
             }
             return bouquets;
        }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)n<(long long)m*k) return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalf=fun(bloomDay,mid,k);
             if(totalf>=m)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};