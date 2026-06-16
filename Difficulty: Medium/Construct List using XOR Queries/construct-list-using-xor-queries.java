class Solution {
    public ArrayList<Integer> constructList(int[][] queries) {
        ArrayList<Integer> arr = new ArrayList<>();
        int sum = 0, q = queries.length;
        for(int i=q-1; i>=0; i--) {
            if(queries[i][0] == 0) {
                arr.add(queries[i][1] ^ sum);
            } else {
                sum ^= queries[i][1]; 
            }
        }
        arr.add(sum);
        Collections.sort(arr);
        return arr;
    }
}