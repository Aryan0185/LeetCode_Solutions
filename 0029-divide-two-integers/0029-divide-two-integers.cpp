class Solution {
public:
    int divide(int dividend, int divisor) {
         if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == divisor) return 1;
        
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;
        
        while (n >= d) {
            long long count = 0;
            while (n > (d << (count + 1)))
                count++;
            n -= d << count;
            ans += 1LL << count;
        }
        if (sign == -1) ans = -ans; 
        
        
       // if (ans > INT_MAX) return INT_MAX;
        //if (ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};