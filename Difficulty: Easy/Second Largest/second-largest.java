class Solution {
    public int getSecondLargest(int[] arr) {
        int largest1 = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++) {
            largest1 = Math.max(largest1, arr[i]);
        }
        
        int largest2 = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++) {
            if(arr[i] < largest1) {
                largest2 = Math.max(largest2, arr[i]);
            }
        }
        
        return largest2 == Integer.MIN_VALUE ? -1 : largest2;
    }
}