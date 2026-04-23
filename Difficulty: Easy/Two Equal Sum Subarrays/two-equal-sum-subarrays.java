class Solution {
    public boolean canSplit(int arr[]) {
        int sum = 0;
        for(int i=0; i<arr.length; i++) {
            sum += arr[i];
        }
        int currSum = 0;
        for(int i=0; i<arr.length; i++) {
            currSum += arr[i];
            if(sum - currSum == currSum) {
                return true;
            }
        }
        return false;
    }
}