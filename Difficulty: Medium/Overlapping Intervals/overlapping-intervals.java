class Solution {
    public ArrayList<int[]> mergeOverlap(int[][] arr) {
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        ArrayList<int[]> ans = new ArrayList<>();
        int index = 0;
        for(int i=1; i<arr.length; i++) {
            if(arr[index][1] >= arr[i][0]) {
                arr[index][1] = Math.max(arr[index][1], arr[i][1]);
            } else {
                ans.add(new int[] { arr[index][0], arr[index][1] });
                index = i;
            }
        }
        ans.add(new int[] { arr[index][0], arr[index][1] });
        return ans;
    }
}