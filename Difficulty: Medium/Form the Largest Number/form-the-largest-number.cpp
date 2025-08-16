class Solution {
  public:
    static bool comparator(string x, string y) {
        string xy = x + y;
        string yx = y + x;
        return xy > yx;
    }
    
    string findLargest(vector<int> &arr) {
        vector<string> nums;
        for(int num : arr) nums.push_back(to_string(num));
        
        sort(nums.begin(), nums.end(), comparator);
        
        string ans = "";
        for(int i=0; i<nums.size(); i++)
            ans += nums[i];
            
        return ans[0] == '0' ? "0" : ans;
    }
};