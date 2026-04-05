class Solution {
    public int totalWays(int[] arr, int target) {
        int N = arr.length;
        int totalSum = 0;

        for (int x : arr)
            totalSum += x;

        int[][] dp = new int[N][2 * totalSum + 1];

        // Fill dp with -1
        for (int i = 0; i < N; i++)
            Arrays.fill(dp[i], -1);

        return findPossibleWays(arr, dp, 0, 0, target, totalSum);
    }
    
    static int findPossibleWays(int[] arr, int[][] dp,
                                int i, int s, int target, int total_sum) {

        // If target is reached, return 1
        if (s == target && i == arr.length)
            return 1;

        // If all elements are processed and target is not reached, return 0
        if (i >= arr.length)
            return 0;

        // s + total_sum to avoid negative values
        if (dp[i][s + total_sum] != -1)
            return dp[i][s + total_sum];

        // Return total count of two cases
        // 1. Add current element
        // 2. Subtract current element
        dp[i][s + total_sum] =
                findPossibleWays(arr, dp, i + 1, s + arr[i], target, total_sum)
              + findPossibleWays(arr, dp, i + 1, s - arr[i], target, total_sum);

        return dp[i][s + total_sum];
    }
}