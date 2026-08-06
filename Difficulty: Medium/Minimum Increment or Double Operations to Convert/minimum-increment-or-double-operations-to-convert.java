class Solution {
    public int countMinOperations(int arr[]) {
        int n = arr.length;
        int steps = 0;
        while(!isAllZero(arr)) {
            if(isAllEven(arr)) {
                for(int i=0; i<n; i++) {
                    arr[i] /= 2;
                }
                steps += 1;
            } else {
                for(int i=0; i<n; i++) {
                    if(arr[i] % 2 != 0) {
                        arr[i] -= 1;
                        steps += 1;
                    }
                }
            }
        }
        return steps;
    }
    
    private boolean isAllZero(int arr[]) {
        for(int num: arr) {
            if(num != 0) {
                return false;
            }
        }
        return true;
    }
    
    private boolean isAllEven(int arr[]) {
        for(int num: arr) {
            if(num % 2 != 0) {
                return false;
            }
        }
        return true;
    }
}