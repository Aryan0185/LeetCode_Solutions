class Solution {
public:
 int fact(int n){
    if(n==1 || n==2)return 1;
    return  fact(n-1)+fact(n-2);
 }
    int fib(int n) {
        if(n==0)return 0;
        return fact(n);
      }
};