class Solution {
public:
    double power(double base ,long long exp){
        if(exp==0)return 1;
        double half=power(base,exp/2);
        if(exp%2==0) return half*half;
        return base*half*half;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){x=1/x; N=-N;}
        return  power(x,N);
    }
};