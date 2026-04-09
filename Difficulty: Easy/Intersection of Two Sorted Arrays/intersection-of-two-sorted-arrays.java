class Solution {
    public static ArrayList<Integer> intersection(int[] a, int[] b) {
        ArrayList<Integer> result = new ArrayList<>();
        
        int i = 0, j = 0;
        
        while (i < a.length && j < b.length) {
            // Skip duplicates in array a
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            
            // Skip duplicates in array b
            if (j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }
            
            if (a[i] == b[j]) {
                result.add(a[i]);
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        int[] a = {1, 1, 2, 2, 2, 4};
        int[] b = {2, 2, 4, 4};

        ArrayList<Integer> ans = intersection(a, b);
        System.out.println(ans);  // Output: [2, 4]
    }
}