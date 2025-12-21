class Solution {
    public ArrayList<Integer> countXInRange(int[] arr, int[][] queries) {
        ArrayList < Integer > ans = new ArrayList < > ();

        for (int i = 0; i < queries.length; i++) {
            int low = queries[i][0];
            int high = queries[i][1];
            int x = queries[i][2];
            int startIndex = -1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (arr[mid] > x) {
                    high = mid - 1;
                } else if (arr[mid] == x) {
                    startIndex = mid;
                    high = mid - 1;
                } else
                    low = mid + 1;
            }

            // get the end index of target number
            int endIndex = -1;
            low = queries[i][0];
            high = queries[i][1];
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (arr[mid] > x) {
                    high = mid - 1;
                } else if (arr[mid] == x) {
                    endIndex = mid;
                    low = mid + 1;
                } else
                    low = mid + 1;
            }

            if (startIndex != -1 && endIndex != -1) {
                ans.add(endIndex - startIndex+1);
            }
            else
            {
                ans.add(0);
            }
        }
        
        return ans;
    }
}