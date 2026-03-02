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
