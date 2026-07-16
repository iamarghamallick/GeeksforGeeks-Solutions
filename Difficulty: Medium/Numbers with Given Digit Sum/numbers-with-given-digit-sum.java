class Solution {

    Integer[][] dp;

    public int solve(int digitCnt, int sum, int n) {

        if (digitCnt == n) {
            return (sum == 0) ? 1 : 0;
        }

        if (dp[digitCnt][sum] != null) {
            return dp[digitCnt][sum];
        }

        int start = (digitCnt == 0) ? 1 : 0;
        int cnt = 0;

        while (start <= 9) {
            if (start <= sum) {
                cnt += solve(digitCnt + 1, sum - start, n);
            }
            start++;
        }

        return dp[digitCnt][sum] = cnt;
    }

    public int countWays(int n, int sum) {

        dp = new Integer[n + 1][sum + 1];

        int ans = solve(0, sum, n);

        return (ans == 0) ? -1 : ans;
    }
}