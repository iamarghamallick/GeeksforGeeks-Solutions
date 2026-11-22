class Solution {
	public int longestSubarrayDivK(int[] arr, int k) {
		int n = arr.length, res = 0;
		Map<Integer, Integer> prefIdx = new HashMap<>();
		int sum = 0;
		
		// Iterate over all ending points
		for (int i = 0; i < n; i++) {
			
			// prefix sum mod k (handling negative prefix sum)
			sum = ((sum + arr[i]) % k + k) % k;
			
			// If sum == 0, then update result with the
			// length of subarray arr[0...i]
			if (sum == 0)
				res = i + 1;
			
			// Update max length for repeating sum
			else if (prefIdx.containsKey(sum)) {
				res = Math.max(res, i - prefIdx.get(sum));
			}
			
			// Store the first occurrence of sum
			else {
				prefIdx.put(sum, i);
			}
		}
		
		return res;
	}
}
