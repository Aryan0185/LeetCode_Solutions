class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int count=0;
        while(ans!=0){
            count++;
            ans=(ans&(ans-1));
        }
      /* for(int i=0;i<=31;i++){
        if(ans&(1<<i)) count++;
       }*/
       return count;
    }
};