class Solution {
    public int countKdivPairs(int[] arr, int k) {
        int[] rem = new int[k];
        for(int i: arr) {
            rem[i % k] += 1;
        }
        int i = 1;
        int j = k-1;
        int ans = (rem[0] * (rem[0] - 1)) / 2;
        while(i <= j) {
            if(i == j) {
                ans += rem[i++] * (rem[j--] - 1) / 2;
            } else {
                ans += rem[i++] * rem[j--];
            }
        }
        return ans;
    }
}