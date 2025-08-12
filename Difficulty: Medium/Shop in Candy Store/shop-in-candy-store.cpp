class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int minCost = 0, maxCost = 0;
        int left = 0, right = prices.size() - 1;
        
        while(left <= right) {
            minCost += prices[left]; // buy the candy with min cost
            right -= k; // take k candies with max cost
            left++;
        }
        
        left = 0, right = prices.size() - 1;
        
        while(left <= right) {
            maxCost += prices[right]; // buy the candy with max cost
            left += k; // take k candies with min cost
            right--;
        }
        
        return { minCost, maxCost };
    }
};