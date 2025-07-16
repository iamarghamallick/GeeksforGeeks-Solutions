class Solution {
  public:
    int countNumbers(int n) {
        // Step 1: Generate primes up to sqrt(n) using Sieve of Eratosthenes
        int max_prime = sqrt(n) + 1; // Upper bound for primes
        vector<bool> is_prime(max_prime + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= max_prime; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= max_prime; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= max_prime; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
        
        // Step 2: Count numbers of the form p^8
        int count = 0;
        for (int p : primes) {
            long long p8 = 1LL * p * p * p * p * p * p * p * p;
            if (p8 > n) break;
            count++;
        }
        
        // Step 3: Count numbers of the form p^2 * q^2 (p < q)
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            long long p2 = 1LL * p * p;
            if (p2 > n) break; // Early exit if p^2 is too large
            // Find primes q > p such that p^2 * q^2 <= n
            long long max_q2 = n / p2;
            int max_q = sqrt(max_q2);
            // Binary search to find the number of primes q > p
            auto it = upper_bound(primes.begin() + i + 1, primes.end(), max_q);
            count += distance(primes.begin() + i + 1, it);
        }
        
        return count;
    }
};