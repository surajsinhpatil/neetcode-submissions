class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //BRUTE FORCE
        int n = prices.size();
        int maxprofit = 0;
        for (int i = 0; i < n; i++){
            int buy = prices[i];
            for (int j = i + 1; j < n; j++){
                int sell = prices[j];
                maxprofit = max(maxprofit, sell - buy);
            }
        }
        return maxprofit;
    }
};
