class Solution {
    int minSubsets(int arr[]) {
        HashSet<Integer> set = new HashSet<>();
        int count = 0;
        for(int num: arr) {
            set.add(num);
        }
        for(int num: arr) {
            if(!set.contains(num - 1)) {
                count++;
            }
        }
        return count;
    }
}