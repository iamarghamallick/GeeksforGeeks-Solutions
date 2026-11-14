class Solution {
	public int maxEqualSum(ArrayList<Integer> s1, ArrayList<Integer> s2, ArrayList<Integer> s3) {
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		
		suffixSum(s1, n1);
		suffixSum(s2, n2);
		suffixSum(s3, n3);
		
		int i = 0, j = 0, k = 0;
		
		while (i < n1 && j < n2 && k < n3) {
			int sum1 = s1.get(i), sum2 = s2.get(j), sum3 = s3.get(k);
			
			if (sum1 == sum2 && sum2 == sum3) {
				return sum1;
			}
			
			if (sum1 >= sum2 && sum1 >= sum3) {
				i++;
			} else if (sum2 >= sum1 && sum2 >= sum3) {
				j++;
			} else {
				k++;
			}
		}
		
		return 0;
	}
	
	private void suffixSum(ArrayList<Integer> arr, int n) {
		for (int i = n - 2; i >= 0; i--) {
			arr.set(i, arr.get(i) + arr.get(i + 1));
		}
	}
}
