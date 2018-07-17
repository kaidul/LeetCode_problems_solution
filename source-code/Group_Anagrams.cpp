class Solution {
    string countingSort(string str) {
        int count[30] = {0};
        for(int j = 0; j < str.length(); ++j) {
            count[(int)(str[j] - 'a')]++; 
        }
        string sortedStr;
        int indx = 0, idx = 0;
        for(char c = 'a'; c <= 'z'; ++c, ++indx) {
            while(count[indx]--) 
                sortedStr.push_back(c);
        }
        return sortedStr;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.empty()) return result;
        unordered_map<string, vector<string>> anagramMap;
        for(string& str : strs) {
            // string sortedStr = str;
            // sort(sortedStr.begin(), sortedStr.end());
        
            string sortedStr = countingSort(str);
        
            anagramMap[sortedStr].push_back(str);
        }
        
        for(auto it = anagramMap.begin(); it != anagramMap.end(); ++it) {
            result.push_back(it->second);
        }
            
        return result;
    }
};