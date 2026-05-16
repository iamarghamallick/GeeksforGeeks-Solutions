class Solution {
    public int findSmallest(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        int res = 1;
        for (int i = 0; i < n && arr[i] <= res; i++) {
            res = res + arr[i];
        }
        return res;
    }
}