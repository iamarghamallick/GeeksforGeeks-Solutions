class Solution {
    public void sort012(int[] arr) {
        int l = 0;
        
        for(int i=0; i<arr.length; i++) {
            if(arr[i] == 0) {
                int temp = arr[i];
                arr[i] = arr[l];
                arr[l] = temp;
                l++;
            }
        }
       
        l = arr.length-1;
       
        for(int i=arr.length-1; i>=0; i--) {
            if(arr[i] == 2) {
                int temp = arr[i];
                arr[i] = arr[l];
                arr[l] = temp;
                l--;
            }
        }
    }
}