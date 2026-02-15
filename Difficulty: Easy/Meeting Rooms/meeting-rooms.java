class Solution {
    static boolean canAttend(int[][] arr) {
        Arrays.sort(arr, (a, b) -> {
            if(a[0] == b[0])
                return a[1] - b[1];
            return a[0] - b[0];
        });
        
        for(int i=0; i<arr.length-1; i++) {
            int b = arr[i][1];
            int c = arr[i+1][0];
            if(c < b) return false;
        }
        
        return true;
    }
}