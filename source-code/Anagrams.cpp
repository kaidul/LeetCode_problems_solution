class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if(strs.size() == 0) return result;
        unordered_map <string, int> Map;
        for(int i = 0; i < strs.size(); ++i) {
            string sortedStr = strs[i];
            
            // sort(sortedStr.begin(), sortedStr.end());
            // counting sort as the string contains only a to z 
            int count[30] = {0};
            for(int j = 0; j < sortedStr.length(); ++j) {
                count[(int)(sortedStr[j] - 'a')]++; 
            }
            int indx = 0, idx = 0;
            for(char c = 'a'; c <= 'z'; ++c, ++indx) {
                while(count[indx]--) sortedStr[idx++] = c;
            }
            
            if(Map.find(sortedStr) != Map.end()) {
                result.push_back(strs[i]);
                if(Map[sortedStr] != -1) {
                    result.push_back(strs[Map[sortedStr]]);
                    Map[sortedStr] = -1;
                }
            } else {
                Map[sortedStr] = i;
            }
        }
        return result;
    }
};