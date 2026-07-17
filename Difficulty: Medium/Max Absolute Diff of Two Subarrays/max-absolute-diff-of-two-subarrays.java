class Solution {

    public int maxDiffSubArrays(int[] arr) {

        int n = arr.length;

        int[] leftMax = new int[n];
        int[] leftMin = new int[n];
        int[] rightMax = new int[n];
        int[] rightMin = new int[n];

        int currSumMax = 0;
        int currSumMin = 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        // Maximum and minimum subarray sum from the left
        for (int i = 0; i < n; i++) {

            currSumMax += arr[i];
            max = Math.max(max, currSumMax);

            currSumMin += arr[i];
            min = Math.min(min, currSumMin);

            leftMax[i] = max;
            leftMin[i] = min;

            if (currSumMax < 0) {
                currSumMax = 0;
            }

            if (currSumMin > 0) {
                currSumMin = 0;
            }
        }

        currSumMax = 0;
        currSumMin = 0;
        max = Integer.MIN_VALUE;
        min = Integer.MAX_VALUE;

        // Maximum and minimum subarray sum from the right
        for (int i = n - 1; i >= 0; i--) {

            currSumMax += arr[i];
            max = Math.max(max, currSumMax);

            currSumMin += arr[i];
            min = Math.min(min, currSumMin);

            rightMax[i] = max;
            rightMin[i] = min;

            if (currSumMax < 0) {
                currSumMax = 0;
            }

            if (currSumMin > 0) {
                currSumMin = 0;
            }
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {

            int curr = Math.max(
                Math.abs(leftMax[i] - rightMin[i + 1]),
                Math.abs(leftMin[i] - rightMax[i + 1])
            );

            ans = Math.max(ans, curr);
        }

        return ans;
    }
}