//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String str1 = sc.next();
            String str2 = sc.next();

            Solution obj = new Solution();
            String ans = obj.betterString(str1, str2);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public static String betterString(String str1, String str2) {
        // Code here
        int dsq1 = distinctSubsequences(str1);
        int dsq2 = distinctSubsequences(str2);
        if(dsq1 >= dsq2)    return str1;
        return str2;
    }
    
    public static int distinctSubsequences(String S) {
        // code here
        int n = S.length();
        int arr[] = new int[26];
        Arrays.fill(arr, -1);
        
        int ans = 0;
        int diff = 0;
        
        for(int i=0; i<n; i++) {
            int x = S.charAt(i)-'a';
            if(i == 0) {
                ans = 1;
                arr[x] = 1;
                continue;
            }
            
            diff = 1+ans;
            if(arr[x] == -1)    ans = ans+diff;
            else    ans = ans+diff - arr[x];
            
            arr[x] = diff;
        }
        
        ans += 1;
        return ans;
    }
}