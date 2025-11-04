class Solution {
    int[] dp;

    int minCost(int[] height) {
        dp = new int[height.length];
        Arrays.fill(dp, -1);
        return cost(0, height);
    }

    int cost(int i, int[] height) {
        int n = height.length;
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i];

        int oneStep = Math.abs(height[i] - height[i + 1]) + cost(i + 1, height);
        int twoStep = Integer.MAX_VALUE;
        if (i + 2 < n)
            twoStep = Math.abs(height[i] - height[i + 2]) + cost(i + 2, height);

        return dp[i] = Math.min(oneStep, twoStep);
    }
    
    // int minCost(int[] height) {
    //     return cost(0, height);
    // }
    
    // int cost(int i, int[] height) {
    //     int n = height.length;
    //     if(i == n-1) return 0;
    //     if(i == n-2) return Math.abs(height[i] - height[i+1]);
    //     return Math.min(
    //         Math.abs(height[i] - height[i+1]) + cost(i+1, height),
    //         Math.abs(height[i] - height[i+2]) + cost(i+2, height)
    //     );
    // }
}