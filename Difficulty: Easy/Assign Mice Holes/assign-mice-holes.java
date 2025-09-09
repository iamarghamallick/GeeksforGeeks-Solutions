class Solution {
    public int assignHole(int[] mices, int[] holes) {
        Arrays.sort(mices);
        Arrays.sort(holes);
        
        int ans = 0;
        for(int i=0; i<mices.length; i++) {
            ans = Math.max(ans, Math.abs(mices[i] - holes[i]));
        }
        
        return ans;
    }
};