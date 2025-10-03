
class Solution {
  public:
    void possibleWordsRec(vector<int> &arr, int index, string &prefix, 
                      vector<string> &padMap, vector<string> &res) {

    // Base case: if the prefix length matches arr size
    if (index == arr.size()) {
        res.push_back(prefix);
        return;
    }

    // Get the corresponding digit
    int digit = arr[index];

    // Skip invalid digits
    if (digit < 2 || digit > 9) {
        possibleWordsRec(arr, index + 1, prefix, padMap, res);
        return;
    }

    // Place all possible letters for this digit
    for (char ch : padMap[digit]) {
        prefix.push_back(ch);
        possibleWordsRec(arr, index + 1, prefix, padMap, res);
        prefix.pop_back();
    }
}

    // Function to find all possible letter combinations
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> res;
        vector<string> padMap = {"", "", "abc", "def", "ghi", "jkl",
                                         "mno", "pqrs", "tuv", "wxyz"};
        string prefix = "";
    
        possibleWordsRec(arr, 0, prefix, padMap, res);
        return res;
    }
};
