class Solution {
  public:
    // Function to compute the prime 
    // factorization of a number 'num'
    vector<vector<int>> primeFactors(int num) {
        vector<vector<int>> factors;
    
        // Count the number of times 2 divides 'num'
        int count = 0;
        while (num % 2 == 0) {
            num /= 2;
            count++;
        }
        if (count > 0) factors.push_back({2, count});
    
        // Check for odd factors starting from 3
        for (int i = 3; i * i <= num; i += 2) {
            count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            if (count > 0) factors.push_back({i, count});
        }
    
        // If 'num' is still greater than 1, it's a prime number
        if (num > 1) factors.push_back({num, 1});
    
        return factors;
    }
    
    int maxKPower(int n, int k) {
        vector<vector<int>> factors = primeFactors(k);
    
        // Initialize result to maximum possible, we'll 
        // take the minimum across all primes
        int result = INT_MAX;
    
        // For each prime factor of k
        for (auto &factor : factors) {
    
            int prime = factor[0];
            int freqInK = factor[1];
            
            int count = 0;
    
            // Count how many times 'prime' appears 
            // in the factorization of n!
            for (int i = 1; i <= n; i++) {
                int x = i;
                
                // Count how many times 'prime' divides 
                // this particular number
                while (x % prime == 0) {
                    count++;
                    x /= prime;
                }
            }
    
            // Since k = prime^freqInK × ..., 
            // we divide the total count by freqInK
            result = min(result, count / freqInK);
        }
    
        return result;
    }
};