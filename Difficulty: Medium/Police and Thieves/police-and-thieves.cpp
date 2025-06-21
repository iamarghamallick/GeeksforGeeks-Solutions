class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int ans = 0;
        int i = 0, j = 0; // track police, thief
        
        while(i < n && j < n) {
            while(i < n && arr[i] != 'P')   i++;
            while(j < n && arr[j] != 'T')   j++;
            
            if(i < n && j < n && abs(i - j) <= k) {
                ans++;
                i++;
                j++;
            } else if(i < n && i < j) {
                i++;
            } else if(j < n && j < i) {
                j++;
            }
        }
        
        return ans;
        
        // TLE
        // int n = arr.size();
        // int ans = 0;
        // int i = 0;
        // while(i < arr.size()) {
        //     if(arr[i] == 'P') {
        //         int start = i - k < 0 ? 0 : i - k;
        //         int end = i + k >= n ? n-1 : i + k;
        //         while(start <= end) {
        //             if(arr[start] == 'T') {
        //                 ans++;
        //                 arr[start] = 'N';
        //                 arr[i] = 'N';
        //                 break;
        //             } else {
        //                 start++;
        //             }
        //         }
        //     } else {
        //         i++;
        //     }
        // }
        
        // return ans;
    }
};