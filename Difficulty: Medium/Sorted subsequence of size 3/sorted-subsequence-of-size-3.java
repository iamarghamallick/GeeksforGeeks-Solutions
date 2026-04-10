class Solution {
    public ArrayList<Integer> find3Numbers(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        int[] smaller = new int[n];
        int[] greater = new int[n];

        // Precompute!
        smaller[0] = -1;
        int minIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIndex]) {
                minIndex = i;
                smaller[i] = -1;
            } 
           else 
                smaller[i] = minIndex;
        }

        greater[n - 1] = -1;
        int maxIndex = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIndex]) {
                maxIndex = i;
                greater[i] = -1;
            } 
            else 
                greater[i] = maxIndex;
        }
        
        // Find a valid subsequence!
        for (int j = 0; j < n; j++) {
            if (smaller[j] != -1 && greater[j] != -1) {
                res.add(arr[smaller[j]]);
                res.add(arr[j]);
                res.add(arr[greater[j]]);
                return res;
            }
        }
        
        // If no valid subsequence, return empty list!
        return res;
    }
}