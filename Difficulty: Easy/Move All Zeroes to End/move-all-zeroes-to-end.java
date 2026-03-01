class Solution {
    void pushZerosToEnd(int[] arr) {
        int nonZeroIndex = 0;
	    
	    for(int i=0; i<arr.length; i++) {
	        if(arr[i] != 0) {
	            if(i != nonZeroIndex) {
	                int temp = arr[i];
	                arr[i] = arr[nonZeroIndex];
	                arr[nonZeroIndex] = temp;
	            }
	            nonZeroIndex++;
	        }
	    }

    }
}