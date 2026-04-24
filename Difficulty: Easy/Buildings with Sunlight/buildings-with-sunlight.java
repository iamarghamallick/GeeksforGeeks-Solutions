class Solution {
    public int visibleBuildings(int arr[]) {
        int sun = arr[0];
        int count = 1;
        for(int i=1; i<arr.length; i++) {
            if(arr[i] >= sun) {
                count++;
                sun = Math.max(sun, arr[i]);
            }
        }
        return count;
    }
}