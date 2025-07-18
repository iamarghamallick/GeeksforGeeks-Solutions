class Solution {
  public:
    int lcmTriplets(int n) {
        if(n < 3) return n;
        else if(n % 2 != 0) return n * (n-1) * (n-2);
        else if(n % 3 == 0) return (n-1) * (n-2) * (n-3);
        return n * (n-1) * (n-3);
    }
};