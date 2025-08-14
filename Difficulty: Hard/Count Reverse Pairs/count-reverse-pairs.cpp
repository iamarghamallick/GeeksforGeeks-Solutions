class Solution {
  public:
    int count = 0;
    
    void modifiedMerge(int left, int mid, int right, vector<int> &arr) {
        int rightPtr = mid + 1;
        for(int leftPtr=left; leftPtr<=mid; leftPtr++) {
            while(rightPtr <= right && arr[leftPtr] > 2 * arr[rightPtr])
                rightPtr++;
            count += (rightPtr - (mid + 1));
        }
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> l(n1), r(n2);
        
        for(int i=0; i<n1; i++)
            l[i] = arr[left + i];
        for(int i=0; i<n2; i++)
            r[i] = arr[mid + 1 + i];
            
        int i = 0, j = 0, k = left;
        
        while(i < n1 && j < n2) {
            if(l[i] < r[j])
                arr[k++] = l[i++];
            else 
                arr[k++] = r[j++];
        }
        
        while(i < n1) {
            arr[k++] = l[i++];
        }
        
        while(i < n1) {
            arr[k++] = r[j++];
        }
    }
  
    void modifiedMergeSort(int left, int right, vector<int> &arr) {
        if(left >= right)
            return;
        
        int mid = (left + right) / 2;
        modifiedMergeSort(left, mid, arr);
        modifiedMergeSort(mid+1, right, arr);
        modifiedMerge(left, mid, right, arr);
    }
    
    int countRevPairs(vector<int> &arr) {
        modifiedMergeSort(0, arr.size()-1, arr);
        return count;
    }
};