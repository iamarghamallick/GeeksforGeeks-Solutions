class Solution {
    public int longestSubarray(int[] arr, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int maxLen = 0;
        int n = arr.length;

        int gtk = 0;  // count of elements greater than k
        int lek = 0;  // count of elements less than or equal to k

        int j = 0;

        while (j < n) {

            // Update counts
            if (arr[j] > k) {
                gtk++;
            } else {
                lek++;
            }

            int diff = gtk - lek;

            /*
             We check (diff - 1) because we assume that
             one more <= k element may have appeared in a previous window.
            */

            if ((diff - 1) < 0 && map.containsKey(diff - 1)) {
                maxLen = Math.max(maxLen, j - map.get(diff - 1));
            } else {
                if ((diff - 1) >= 0) {
                    maxLen = Math.max(maxLen, j + 1);
                }
            }

            // Store first occurrence of diff
            if (!map.containsKey(diff)) {
                map.put(diff, j);
            }

            j++;
        }

        return maxLen;
    }
}