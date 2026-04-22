class Solution {
    public ArrayList<Integer> findMean(int[] arr, int[][] queries) {
        int n = arr.length;
        int[] prefix = new int[n];
        prefix[0] = arr[0];
        for(int i=1; i<arr.length; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for(int[] query: queries) {
            int i = query[0];
            int j = query[1];
            ans.add((prefix[j] - (i > 0 ? prefix[i-1] : 0)) / (j-i+1));
        }
        return ans;
    }
}