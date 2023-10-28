//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int ans = ob.is_bleak(n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    public int countSetbit(int x) {
        int count = 0;
        while(x>0) {
            if((x&1) == 1)    count++;
            x /= 2;
        }
        return count;
    }
    
    public int is_bleak(int n)
    {
        // Code here
        int m = n;
        int x = 0;
        while(n > 0) {
            n /= 2;
            x++;
        }
        
        for(int i=m-1; i>= m-32; i--) {
            if(i + countSetbit(i) == m) return 0;
        }
        
        return 1;
    }
}