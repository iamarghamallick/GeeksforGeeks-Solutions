class Solution {
    public ArrayList<Integer> cntInRange(int[] arr, int[][] queries) {
        int count = 0;
        Arrays.sort(arr);
        ArrayList<Integer> result = new ArrayList<>();
        
        for (int querie[] : queries) {
            for (int i : arr) {
                if (i > querie[1]) break;
                if (i >= querie[0] && i <= querie[1]) count++;
            }
            result.add(count);
            count = 0;
        }
        
        return result;
    }
}
