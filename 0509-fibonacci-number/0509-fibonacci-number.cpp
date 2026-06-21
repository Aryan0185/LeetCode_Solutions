class Solution {
public:
     int fact(int nums){
        if(nums==1 || nums==2)return 1;
        return fact(nums-1)+fact(nums-2);
     }
    int fib(int n) {
        if(n==0)return 0;
        return  fact(n);
      }
};