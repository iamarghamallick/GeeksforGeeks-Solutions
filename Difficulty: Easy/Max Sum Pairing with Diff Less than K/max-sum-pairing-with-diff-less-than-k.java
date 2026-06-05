class Solution {
    public int sumDiffPairs(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);
        int sum = 0;
        int i = n-1;
        while(i > 0) {
            int diff = arr[i] - arr[i-1];
            if(diff < k) {
                sum += (arr[i] + arr[i-1]);
                i -= 2;
            } else {
                i--;
            }
        }
        return sum;
    }
}