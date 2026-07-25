class Solution {

    public int maximumSum(int[][] mat, int k) {
        int n = mat.length;

        int maxGlobal = Integer.MIN_VALUE;

        // Compress every continuous block of k rows into a 1D array
        for (int i = 0; i <= n - k; i++) {

            // colSums[j] stores the sum of column j for rows i to i + k - 1
            int[] colSums = new int[n];

            for (int r = i; r < i + k; r++) {
                for (int j = 0; j < n; j++) {
                    colSums[j] += mat[r][j];
                }
            }

            // Apply sliding window of size k on the compressed array
            int currentSubgridSum = 0;

            for (int j = 0; j < k; j++) {
                currentSubgridSum += colSums[j];
            }

            maxGlobal = Math.max(maxGlobal, currentSubgridSum);

            for (int j = k; j < n; j++) {
                currentSubgridSum += colSums[j] - colSums[j - k];
                maxGlobal = Math.max(maxGlobal, currentSubgridSum);
            }
        }

        return maxGlobal;
    }
}