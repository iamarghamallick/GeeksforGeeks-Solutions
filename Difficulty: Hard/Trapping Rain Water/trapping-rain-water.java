//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().maxWater(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int maxWater(int arr[]) {
        int n=arr.length;
        int leftmax[]=new int[n];
        leftmax[0]=arr[0];
        for(int i=1;i<n;i++){
            leftmax[i]=Math.max(leftmax[i-1],arr[i]);
        }
        
        int rightmax[]=new int[n];
        rightmax[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            rightmax[i]=Math.max(rightmax[i+1],arr[i]);
        }
        
        int trappedwater=0;
        for(int i=0;i<n;i++){
            int waterlevel=Math.min(leftmax[i],rightmax[i]);
            trappedwater+=waterlevel-arr[i];
        }
        return trappedwater;
    }
}
