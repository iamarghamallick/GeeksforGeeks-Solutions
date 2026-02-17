
class Solution {
    public static int overlapInt(int[][] arr) {
        List<int[]> events = new ArrayList<>();

        // Convert birth & death logs into timeline events
        for (int[] log : arr) {
            events.add(new int[]{log[0], +1}); // birth
            events.add(new int[]{log[1], -1}); // death
        }
        
        // If years are same, +1 (birth) should come before -1 (death)
        Collections.sort(events, (a, b) -> {
            if (a[0] == b[0]) {
                return b[1] - a[1]; // +1 first
            }
            return a[0] - b[0];     // sort by year
        });
        
        int curr = 0;
        int maxPop = 0;
        
        // Traverse sorted events and calculate maximum population
        for (int[] e : events) {
            curr += e[1];
            maxPop = Math.max(curr, maxPop);
        }
        
        return maxPop;

    }
}
