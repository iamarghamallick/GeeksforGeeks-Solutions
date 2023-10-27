//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String S = read.readLine();

            Solution ob = new Solution();
            
            System.out.println(ob.minimumNumberOfDeletions(S));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int minimumNumberOfDeletions(String s) {
        //your code here
        int n = s.length();
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        String s2 = sb.toString();
        
        int arr[][] = new int[n+1][n+1];
        
        for(int i=n; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i == n || j == n)
                    arr[i][j] = 0;
                else if(s.charAt(i) == s2.charAt(j))
                    arr[i][j] = 1 + arr[i+1][j+1];
                else 
                    arr[i][j] = Math.max(arr[i][j+1], arr[i+1][j]);
            }
        }
        
        return n - arr[0][0];
    }
}