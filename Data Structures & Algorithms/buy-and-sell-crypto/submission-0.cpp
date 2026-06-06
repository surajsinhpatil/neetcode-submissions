class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //OPTIMAL SOL
        int n = prices.size();
        int l = 0;
        int r = 1;
        int maxprofit = 0;

        while (r < n){
            if(prices[r] > prices[l]){
                int profit = prices[r] - prices[l];
                maxprofit = max(maxprofit, profit);
            }
            else {
                l = r; //we found a cheaper buy price
            }
            r++;
        }
        return maxprofit;
    }
};
