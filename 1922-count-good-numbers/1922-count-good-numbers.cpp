class Solution {
    const int MOD=1e9 + 7;
    long long modpow(long long base,long long exp,long long mod){
        long long res=1;
        base%=mod;
        while(exp>0){
            if(exp&1)
            res=res*base%mod;
            base=base*base%mod;
            exp>>=1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        return modpow(5,even,MOD)*modpow(4,odd,MOD)%MOD;
    }
};