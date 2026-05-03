class Solution {
    ArrayList<Integer> sortBySetBitCount(int[] arr) {
        int n = arr.length;
        Integer[] temp = new Integer[n];
        
        for(int i=0; i<n; i++) {
            temp[i] = arr[i];
        }
        
        Arrays.sort(temp, (a, b) -> {
            int count1 = countBits(a);
            int count2 = countBits(b);
            if(count1 != count2) {
                return count2 - count1;
            }
            return 0;
        });
        
        ArrayList<Integer> result = new ArrayList<>();
        for(int num : temp) {
            result.add(num);
        }
        
        return result;
    }
    
    private int countBits(int n) {
        int count = 0;
        while(n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
}