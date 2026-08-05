class Solution {
    public int countSubarray(int[] arr, int l, int r) {
        return solve(arr, r) - solve(arr, l - 1);
    }

    public static int solve(int[] arr, int r) {
        int cnt = 0;
        int s = 0;
        int i = 0;
        int j = 0;
        int n = arr.length;

        while (j < n) {
            s += arr[j];

            while (s > r && i <= j) {
                s -= arr[i];
                i++;
            }

            j++;
            cnt += (j - i + 1);
        }

        return cnt;
    }
}