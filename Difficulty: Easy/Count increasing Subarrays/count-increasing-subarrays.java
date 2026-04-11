class Solution {
    public int countIncreasing(int[] arr) {
        int n = arr.length;
        long ans = 0;
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }

        return (int) ans;
    }
}
