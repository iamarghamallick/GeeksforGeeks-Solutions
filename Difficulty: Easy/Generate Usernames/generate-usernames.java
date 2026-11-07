class Solution {
	public ArrayList<String> generateUsernames(String[] arr) {
		HashSet<String> set1 = new HashSet<>();
		HashSet<String> set2 = new HashSet<>();
		ArrayList<String> list = new ArrayList<>();
		
		for (String str: arr) {
			set1.add(str);
		}
		
		for (String str: arr) {
			if (!set2.contains(str)) {
				list.add(str);
				set2.add(str);
			} else {
				int x = 1;
				while (set1.contains(str + x)) {
					x++;
				}
				set2.add(str + x);
				set1.add(str + x);
				list.add(str + x);
			}
		}
		
		return list;
	}
}
