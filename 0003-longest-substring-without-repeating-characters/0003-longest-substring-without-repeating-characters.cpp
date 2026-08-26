class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int idx[128];
        memset(idx,-1,sizeof(idx));
        int ans=0,left=0;
        for(int i=0;i<(int)s.size();i++){
            if(idx[(int)s[i]]>=left)
             left=idx[(int)s[i]]+1;
            idx[(int)s[i]]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};