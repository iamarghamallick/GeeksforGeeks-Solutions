//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        
        vector <int> freq(n+1, 0);
        priority_queue <int, vector <int>, greater <int>> room;
        priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> pq;
        
        for(int i = 0; i < n; i++) room.push(i);
        
        for(int i = 0; i < m; i++){
            int st = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - st;
            
            while(!pq.empty() && st >= pq.top().first) {
                int y = pq.top().second;
                pq.pop();
                room.push(y);
            }
            
            if(room.empty()){
                int x = pq.top().first;
                int y = pq.top().second;
                pq.pop();
                
                pq.push(make_pair(x + duration, y));
                freq[y]++;
            }
            else{
                int book = room.top();
                room.pop();
                
                pq.push(make_pair(meetings[i][1], book));
                freq[book]++;
            }
        }
        
        int roomNum = 0;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(freq[i] > mx){
                mx = freq[i];
                roomNum = i;
            }
        }
        
        return roomNum;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends