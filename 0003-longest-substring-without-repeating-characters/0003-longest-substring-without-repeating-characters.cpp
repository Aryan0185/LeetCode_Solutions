class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int l=0,r=0,maxlen=0;
        int n=s.size();
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(l,mpp[s[r]]+1);
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};