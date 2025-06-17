class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + arr[i];
        
        int ans = INT_MAX, prev = 0;
        
        for(int i=0; i<n; i++){
            if(i > 0) prev = pre[i-1];
            int pos = upper_bound(arr.begin()+i, arr.end(), arr[i]+k)-arr.begin();
            int total = pos>0 ? pre[n-1] - pre[pos-1] : 0;
            int allowed = (n-pos) * (arr[i]+k);
            int extracoins = prev + total-  allowed;
            ans = min(ans, extracoins);
        }
        
        return ans;
    }
};
