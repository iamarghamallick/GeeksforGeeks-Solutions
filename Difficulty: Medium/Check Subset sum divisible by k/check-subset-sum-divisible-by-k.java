class Solution {
    public boolean divisibleByK(int[] arr, int k) {
        boolean[] dp = new boolean[k];

        for (int num : arr) {

            boolean[] next = dp.clone();

            // Current number alone
            next[num % k] = true;

            // Add current number to previous subsets
            for (int rem = 0; rem < k; rem++) {
                if (dp[rem]) {
                    next[(rem + num) % k] = true;
                }
            }

            dp = next;

            if (dp[0]) {
                return true;
            }
        }

        return false;
    }
}