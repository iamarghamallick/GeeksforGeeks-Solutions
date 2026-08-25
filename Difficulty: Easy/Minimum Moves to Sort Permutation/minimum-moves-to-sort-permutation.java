class Solution {
    public int minMoves(int[] arr) {
        int n = arr.length;
        int[] count = new int[n+1];
        
        for(int num: arr) {
            if(count[num-1] != 0) {
                count[num] = count[num-1] + 1;
            } else {
                count[num] = 1;
            }
        }
        
        int lcs = 0;
        for(int num: count) {
            lcs = Math.max(lcs, num);
        }
        
        return n - lcs;
    }
}