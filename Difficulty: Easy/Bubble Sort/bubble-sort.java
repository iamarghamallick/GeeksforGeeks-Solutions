class Solution {
    public void bubbleSort(int[] arr) {
        int n = arr.length;
        
        for(int i=0; i<n-1; i++) {
            boolean swapped = false;
            
            for(int j=0; j<n-1-i; j++) {
                if(arr[j] > arr[j+1]) {
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    
                    swapped = true;
                }
            }
            
            if(!swapped) break;
        }
    }
}