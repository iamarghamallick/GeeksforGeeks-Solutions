class Solution {
	public ArrayList<ArrayList<Integer>> formCoils(int n) {
		int m = 8 * n * n;
		
		ArrayList<Integer> coil1 = new ArrayList<>();
		ArrayList<Integer> coil2 = new ArrayList<>();
		
		int first = 8 * n * n + 2 * n;
		coil1.add(first);
		
		int curr = first;
		int flag = 1, step = 2;
		
		// Generate the standard first coil.
		while (coil1.size() < m) {
			for (int i = 0; i < step && coil1.size() < m; i++) {
				curr -= 4 * n * flag;
				coil1.add(curr);
			}
			
			for (int i = 0; i < step && coil1.size() < m; i++) {
				curr += flag;
				coil1.add(curr);
			}
			
			flag *= -1;
			step += 2;
		}
		
		// Generate the second coil using complementary values.
		for (int i = 0; i < m; i++)
			coil2.add(16 * n * n + 1 - coil1.get(i));
		
		Collections.reverse(coil1);
		Collections.reverse(coil2);
		
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
		ans.add(coil2);
		ans.add(coil1);
		
		return ans;
	}
}
