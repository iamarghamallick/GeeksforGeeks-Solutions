class Solution {
    public int subarrayXor(int[] arr) {
        int ans = 0;
        int co = 1;
        if(arr.length % 2 == 0) return 0;
        
        for(int i: arr) {
            if(co % 2 != 0) ans ^= i;
            co++;
        }
        
        return ans;
    }
}