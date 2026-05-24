class Solution {
    public int coin(int[] arr) {
        return Arrays.stream(arr).min().getAsInt();
    }
}