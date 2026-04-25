class Solution {
    void mergeSort(int arr[], int l, int r) {
        if(l >= r) {
            return;
        }
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    
    void merge(int arr[], int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        
        int[] left = new int[n1];
        int[] right = new int[n2];
        
        for(int i=0; i<n1; i++) {
            left[i] = arr[l+i];
        }
        for(int j=0; j<n2; j++) {
            right[j] = arr[mid+1+j];
        }
        
        int i = 0;
        int j = 0;
        int k = l;
        
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }
        
        while(i < n1) {
            arr[k++] = left[i++];
        }
        
        while(j < n2) {
            arr[k++] = right[j++];
        }
    }
}