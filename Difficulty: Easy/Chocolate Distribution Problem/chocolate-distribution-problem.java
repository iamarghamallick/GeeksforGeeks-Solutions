// User function Template for Java

class Solution {
    public int findMinDiff(ArrayList<Integer> arr, int m) {
        ArrayList<Integer> res = new ArrayList<>();
        Collections.sort(arr); // so that close elements will be together
        
        int i = 0; // start window
        m -= 1; // end window
        int min = Integer.MAX_VALUE; // ans
        
        while(m < arr.size()) { // for each waindow os size m
            min = Math.min(min, Math.abs(arr.get(i) - arr.get(m))); // min
            m++;
            i++;
        }
        
        return min;
    }
}