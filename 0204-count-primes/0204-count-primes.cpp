class Solution {
public:
    int countPrimes(int n) {
        if(n==0 ||n==1)return 0;
        vector<bool>isPrime(n,true);
        int count=0;
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i<n;i++){
            if(isPrime[i]){
                count++;
                int k=2;
                int j=i*k;
                while(j<n){
                    isPrime[j]=false;
                    j=j+i;
                }
            }
        }
        return count;
    }
};