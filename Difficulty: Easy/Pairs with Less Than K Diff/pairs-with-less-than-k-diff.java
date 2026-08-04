class Solution {
    public static int countPairs(int arr[], int k) {
        Arrays.sort(arr);
        
        int count = 0, i = 0, j = 0;
        while(j < arr.length) {
            while(i <= j && Math.abs(arr[i] - arr[j]) >= k) {
                i++;
            }
            count += (j-i);
            j++;
        }
        
        return count;
    }
}
