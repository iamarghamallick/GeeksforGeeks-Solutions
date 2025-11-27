class Solution {
    int subsetXORSum(int arr[]) {
        int OR = 0, n = arr.length;
        for(int x : arr) OR |= x;
        return OR * (int)Math.pow(2, n-1); 
    }
}