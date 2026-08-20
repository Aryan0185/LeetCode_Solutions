class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minprices=prices[0];
        for(int i=0;i<prices.size();i++){
            maxprofit=max(maxprofit,prices[i]-minprices);
            minprices=min(minprices,prices[i]);
        }
        return maxprofit;
    }
};