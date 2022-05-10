class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = prices[0];
        int profit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] > bought){
                profit += prices[i] - bought;
                bought = prices[i];
            }
            else{
                bought = prices[i];
            }
        }
        return profit;
    }
};