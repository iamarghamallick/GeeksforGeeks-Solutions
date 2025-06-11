class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        int n = color.size();
        stack<pair<int, int>> st; // pair<color[i], radius[i]>
        
        for(int i=0; i<n; i++) {
            if(st.empty())
                st.push({color[i], radius[i]});
            else {
                int prevCol = st.top().first;
                int prevRad = st.top().second;
                
                int currCol = color[i];
                int currRad = radius[i];
                
                if(prevCol == currCol && 
                   prevRad == currRad)
                    st.pop();
                else 
                    st.push({currCol, currRad});
            }
        }
        
        return st.size();
    }
};