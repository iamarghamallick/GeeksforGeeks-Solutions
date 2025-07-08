class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        
        unordered_map<int, int> freq;
        for(int num : arr) freq[num]++;
        
        stack<pair<int, int>> st; // <num, freq[num]>
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top().second <= freq[arr[i]]) {
                st.pop();
            }
            
            if(!st.empty()) {
                ans[i] = st.top().first;
            }
            
            st.push({arr[i], freq[arr[i]]});
        }
        
        return ans;
    }
};
