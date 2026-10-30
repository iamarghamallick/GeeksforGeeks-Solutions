class Solution {
	public int cntSubsets(int arr[], int l, int r) {
		final long M = 1000000007L;
		int n = arr.length;
		
		HashMap<Integer, Integer> mp = new HashMap<>();
		for (int num : arr) {
			mp.put(num, mp.getOrDefault(num, 0) + 1);
		}
		
		// Precompute powers of 2 modulo M.
		long[] power = new long[n + 1];
		Arrays.fill(power, 1);
		for (int i = 1; i <= n; i++) {
			power[i] = (power[i - 1] * 2) % M;
		}
		
		long res = 0;
		long cur = 1;
		int seen = 0;
		
		// Ensure every value smaller than l is present.
		for (int i = 0; i < l; i++) {
			int freq = mp.getOrDefault(i, 0);
			
			if (freq == 0) {
				return 0;
			}
			
			seen += freq;
			cur = (cur * (power[freq] - 1 + M)) % M;
		}
		
		// Count subsets for each possible MEX.
		for (int i = l; i <= r; i++) {
			int freq = mp.getOrDefault(i, 0);
			
			long here = (cur * power[n - seen - freq]) % M;
			res = (res + here) % M;
			
			// No larger MEX is possible if i is absent.
			if (freq == 0) {
				return (int)res;
			}
			
			seen += freq;
			cur = (cur * (power[freq] - 1 + M)) % M;
		}
		
		return (int)res;
	}
}
