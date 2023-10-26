//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
        	int n = sc.nextInt();
        	int[] array = new int[n];
        	for (int i=0; i<n ; i++ ) {
        		array[i] = sc.nextInt();
        	}
            Solution ob = new Solution();
            long[] ans = new long[n];
            ans = ob.productExceptSelf(array, n); 

           	for (int i = 0; i < n; i++) { 
				System.out.print(ans[i]+" ");
			} 
            System.out.println();
            t--;
        }
    } 
} 
  


// } Driver Code Ends


//User function Template for Java


class Solution 
{ 
	public static long[] productExceptSelf(int nums[], int n) 
	{ 
        // code here
        if(n == 1) 
            return new long[] {1};
        
        long left[] = new long[n];
        long right[] = new long[n];
        
        left[0] = 1;
        right[n-1] = 1;
        
        for(int i=1; i<n; i++) {
            left[i] = left[i-1]*nums[i-1];    
        }
        for(int j=n-2; j>=0; j--) {
            right[j] = right[j+1]*nums[j+1];
        }
        
        long res[] = new long[n];
        for(int i=0; i<n; i++) {
            res[i] = left[i]*right[i];
        }
        
        return res;
	} 
} 
