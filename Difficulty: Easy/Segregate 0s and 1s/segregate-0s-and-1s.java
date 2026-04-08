class Solution {
    void segregate0and1(int[] arr) {
        int zeroCount = 0, oneCount = 0;
        for(int i=0; i<arr.length; i++) {
            if(arr[i] == 0) zeroCount++;
            else oneCount++;
        }
        int i = 0;
        while(zeroCount-- > 0)  arr[i++] = 0;
        while(oneCount-- > 0)   arr[i++] = 1;
    }
}
