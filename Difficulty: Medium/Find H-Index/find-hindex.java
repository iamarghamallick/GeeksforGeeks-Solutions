class Solution {
    public int hIndex(int[] citations) {
        int start=1,end=citations.length;
        while(start<=end) {
            int mid = start+(end-start)/2;
            if(check(mid,citations)) {
                start = mid+1;
            }
            else {
                end=mid-1;
            }
        }
        return end;
    }
    public boolean check(int num,int[] arr) {
        int count=0;
        for(int i=0;i<arr.length;i++) {
            if(arr[i]>=num) {
                count++;
            }
        }
        return count>=num;
    }
}