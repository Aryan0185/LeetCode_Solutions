class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int maxlen=0,maxfeq=0,left=0;
        for(int right=0;right<s.size();right++){
            count[s[right]-'A']++;
            maxfeq=max(maxfeq,count[s[right]-'A']);
            while((right-left+1)-maxfeq>k){
                count[s[left]-'A']--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};