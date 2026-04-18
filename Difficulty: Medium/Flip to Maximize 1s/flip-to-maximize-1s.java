class Solution {
    int maxOnes(int[] arr) {
        int count = 0;
        int total = 0;
        int ans = 0;
        
        for(int i=0; i<arr.length; i++) {
            if(count <= 0) {
                count = 0;
            }
            
            if(arr[i] == 1) {
                count--;
                total++;
            }
            
            if(arr[i] == 0) {
                count++;
            }
            
            ans = Math.max(ans, count);
        }
        
        return total + ans;
    }
};