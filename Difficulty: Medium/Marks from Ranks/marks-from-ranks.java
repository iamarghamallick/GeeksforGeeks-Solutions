class Solution {
	public ArrayList<Integer> getMarks(int[] l, int[] r, int[] rank) {
		ArrayList<Integer> ans = new ArrayList<>();
		int c = 0, idx = 0;
		
		for (int i: rank) {
			while ((c + r[idx]-l[idx]+1)<i) {
				c += r[idx]-l[idx]+1;
				idx++;
			}
			ans.add(l[idx]+(i - c-1));
			c = 0;
			idx = 0;
		}
		
		return ans;
	}
}
