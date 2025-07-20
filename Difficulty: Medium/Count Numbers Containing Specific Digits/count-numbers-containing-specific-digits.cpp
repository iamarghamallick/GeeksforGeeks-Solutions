class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        int start = pow(10, n-1);
        int end = pow(10, n) - 1;
        int total = end - start + 1;
        bool zero = true;
        
        for(int num : arr) if(num == 0) zero = false;
        
        int invalid = zero ?
                      (10 - arr.size() - 1) * pow(10 - arr.size(), n - 1) :
                      pow(10 - arr.size(), n);
    
        return total - invalid;
    }
};
