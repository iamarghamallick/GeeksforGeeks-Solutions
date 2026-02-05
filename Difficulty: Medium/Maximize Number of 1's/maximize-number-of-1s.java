class Solution {
    public int maxOnes(int arr[], int k) {
        int n = arr.length, s = 0, e = 0, cnt = 0, ans = 0; 
        
        while(e < n) {
            if(arr[e] == 0) cnt++;
            while(cnt > k) {
                if(arr[s] == 0) cnt--;
                s++;
            }
            ans = Math.max(ans, e - s + 1);
            e++;
        }
        
        return ans;
    }
}