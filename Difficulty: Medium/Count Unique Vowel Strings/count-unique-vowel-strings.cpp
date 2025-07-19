class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char, int> map;
        int fact = 0, mult = 1;
        
        for(char ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u')
               map[ch]++;
        }
        
        if(!map.empty()) fact = 1;
        
        for(int i = map.size(); i>=1; i--) fact *= i;
        
        for(auto i=map.begin(); i!=map.end(); i++) mult *= i->second;
        
        return fact * mult;
    }
};