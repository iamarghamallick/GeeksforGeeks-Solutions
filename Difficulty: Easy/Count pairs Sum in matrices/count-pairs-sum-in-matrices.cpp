class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        vector<int>ans1;
        vector<int>ans2;
        for (int i=0;i<mat1.size();i++){
            for (int j=0; j< mat1.size(); j++){
                ans1.push_back(mat1[i][j]);
                ans2.push_back(mat2[i][j]);
            }
        }
        int i=0;
        int count=0;
        int j= ans1.size()-1;
        while(i<ans1.size() && j>=0){
            int sum=ans1[i]+ans2[j];
            if(sum==x){
                count+=1;
                i++;
                j--;
            }
            else if(sum< x)
                i++;
            else
                j--;
        }
        return count;
    }
};