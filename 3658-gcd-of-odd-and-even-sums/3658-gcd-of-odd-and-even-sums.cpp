class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=2,sumodd=1;
        for(int i=0;i<=n;i++){
             sumeven+=(2*i+1);
             sumodd+=2*i+2;
        }
        return -(sumeven-sumodd);
    }
};