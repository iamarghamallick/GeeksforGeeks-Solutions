class Solution {
    static ArrayList<Integer> diagView(int mat[][]) {
        int n = mat.length ;
        
        HashMap<Integer, ArrayList<Integer>> map = new HashMap<>() ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(map.isEmpty() || !map.containsKey(i + j)){
                    map.put(i+j , new ArrayList<>()) ;
                    map.get(i+j).add(mat[i][j]) ;
                }
                else 
                    map.get(i+j).add(mat[i][j]) ;    
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>() ;
        for(int d = 0 ; d <= 2 * n - 2 ; d++){
            if(map.containsKey(d)){
                ans.addAll(map.get(d)) ;
            }
        }
        
        return ans;
    }
}
