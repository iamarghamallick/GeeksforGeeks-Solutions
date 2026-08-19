class Solution {
	
	public int countTriplets(int[] arr, int l, int r) {
	    int n = arr.length;
		Arrays.sort(arr);
		return countTripletsLessThanVal(arr, r) - 
		        countTripletsLessThanVal(arr, l-1);
	}
	
	private int countTripletsLessThanVal(int[] arr, int val) {
	    int n = arr.length;
	    int ans = 0;
	    
	    for(int i=0; i<n-2; i++) {
		    int j = i+1;
		    int k = n-1;
		    
		    while(j < k) {
		        int sum = arr[i] + arr[j] + arr[k];
		        if(sum > val) {
		            k--;
		        } else {
		            ans += (k - j);
		            j++;
		        }
		    }
		}
		
		return ans;
	}
}
