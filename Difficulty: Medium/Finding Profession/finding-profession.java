class Solution {
    public String profession(int level, int pos) {
        int flips = Integer.bitCount(pos - 1); 
        return (flips % 2 == 0) ? "Engineer" : "Doctor";
    }
}