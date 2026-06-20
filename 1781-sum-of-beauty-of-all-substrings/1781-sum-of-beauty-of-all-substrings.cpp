class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int totalbeauty=0;
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxf=0,minf=n;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxf=max(freq[k],maxf);
                        minf=min(freq[k],minf);
                    }
                }
                totalbeauty+=maxf-minf;
            }
        }
        return totalbeauty;
    }
};