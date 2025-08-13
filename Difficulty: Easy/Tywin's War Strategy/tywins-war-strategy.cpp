class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int luckySoldiers = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i]%k == 0){
                luckySoldiers++;
            } else {
                int soldiersToBeAdded = k - (arr[i]%k);
                pq.push(soldiersToBeAdded);
            }
        }
        
        int totalToBeAdded = 0;
        while((luckySoldiers<ceil(n/2.0)) && !pq.empty()){
            totalToBeAdded += pq.top();
            pq.pop();
            luckySoldiers++;
        }
        
        return totalToBeAdded;
    }
};