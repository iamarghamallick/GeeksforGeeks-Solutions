class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        int n = arr.length;
        int maxSum = 0, windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        maxSum = windowSum;
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            if (windowSum > maxSum) maxSum = windowSum;
        }
        return maxSum;
    }
}