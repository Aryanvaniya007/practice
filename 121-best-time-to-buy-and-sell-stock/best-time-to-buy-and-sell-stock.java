class Solution {
    public int maxProfit(int[] prices) {
        int min_price = prices[0];
        int profit = 0;
        for(int i=0;i<prices.length;i++)
        {
            int cost = -min_price + prices[i];
            profit = Math.max(cost,profit);
            min_price = Math.min(min_price,prices[i]);
        }
        return profit;
    }
}