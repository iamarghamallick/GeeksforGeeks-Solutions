class Solution {
    public int maxProfit(int arr[], int k) {
        int n = arr.length;
        
        if (n == 0) return 0;
        
        int cash = 0;          // profit when not holding stock
        int hold = -arr[0];    // profit when holding stock
        
        for (int i = 1; i < n; i++) {
            int prevCash = cash;
            
            // Sell stock
            cash = Math.max(cash, hold + arr[i] - k);
            
            // Buy stock
            hold = Math.max(hold, prevCash - arr[i]);
        }
        
        return cash;
    }
}