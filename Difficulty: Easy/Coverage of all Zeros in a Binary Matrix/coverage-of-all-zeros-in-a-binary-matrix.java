class Solution {
    public int findCoverage(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        int totalCoverage = 0;
        
        // Iterate through each cell in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Only process if the cell is 0
                if (mat[i][j] == 0) {
                    int coverage = 0;
                    
                    // Check left direction
                    for (int l = j - 1; l >= 0; l--) {
                        if (mat[i][l] == 1) {
                            coverage++;
                            break;
                        }
                    }
                    
                    // Check right direction
                    for (int r = j + 1; r < cols; r++) {
                        if (mat[i][r] == 1) {
                            coverage++;
                            break;
                        }
                    }
                    
                    // Check up direction
                    for (int u = i - 1; u >= 0; u--) {
                        if (mat[u][j] == 1) {
                            coverage++;
                            break;
                        }
                    }
                    
                    // Check down direction
                    for (int d = i + 1; d < rows; d++) {
                        if (mat[d][j] == 1) {
                            coverage++;
                            break;
                        }
                    }
                    
                    totalCoverage += coverage;
                }
            }
        }
        
        return totalCoverage;
    }
}