class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, buy = prices[0];
        for(int price : prices) {
            buy = Math.min(buy, price);
            ans = Math.max(ans, price - buy);
        }
        return ans;
    }
}