class Solution {
public: 
    bool solve(long long cur,int n){
       if(cur==n)return true;
       if(cur>n)return false;
       return solve(cur*3,n);
    }
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        return solve(1,n);
    }
};