class Solution {

    int minOperations(int[] b) {
        int n = b.length;
        boolean[] visited = new boolean[n];
        long MOD = 1000000007L;

        // Stores the maximum exponent required for each prime factor
        Map<Integer, Integer> maxPrimePowers = new HashMap<>();

        // Find all cycle lengths
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int cycleLength = 0;
                int curr = i;

                // Traverse the current cycle
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = b[curr] - 1; // Convert 1-based index to 0-based
                    cycleLength++;
                }

                if (cycleLength > 1) {
                    getPrimeFactors(cycleLength, maxPrimePowers);
                }
            }
        }

        // Compute LCM modulo 1e9+7
        long ans = 1;
        for (Map.Entry<Integer, Integer> entry : maxPrimePowers.entrySet()) {
            int prime = entry.getKey();
            int power = entry.getValue();

            ans = (ans * powerMod(prime, power, MOD)) % MOD;
        }

        return (int) ans;
    }

    // Updates the maximum exponent of each prime factor
    private static void getPrimeFactors(int num, Map<Integer, Integer> maxPrimePowers) {
        int temp = num;

        for (int i = 2; i * i <= temp; i++) {
            if (temp % i == 0) {
                int count = 0;

                while (temp % i == 0) {
                    count++;
                    temp /= i;
                }

                maxPrimePowers.put(
                    i,
                    Math.max(maxPrimePowers.getOrDefault(i, 0), count)
                );
            }
        }

        if (temp > 1) {
            maxPrimePowers.put(
                temp,
                Math.max(maxPrimePowers.getOrDefault(temp, 0), 1)
            );
        }
    }

    // Fast modular exponentiation
    private static long powerMod(long base, long exp, long mod) {
        long res = 1;
        base %= mod;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = (res * base) % mod;
            }

            base = (base * base) % mod;
            exp >>= 1;
        }

        return res;
    }
}