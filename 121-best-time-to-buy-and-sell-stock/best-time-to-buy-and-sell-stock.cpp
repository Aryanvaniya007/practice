class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int profit = 0;
        for(int i=0;i<prices.size();i++)
        {
            int cost = prices[i] - min_price;
            profit = max(profit,cost);
            min_price = min(min_price,prices[i]);
        }
        return profit;
    }
};