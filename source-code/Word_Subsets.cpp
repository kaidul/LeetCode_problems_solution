class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int n = (int)A.size();
        unordered_map<int, int> freqMap[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int)A[i].length(); j++) {
                freqMap[i][A[i][j]] ++;
            }
        }
        
        unordered_map<int, int> maxFreqMap;
        for (string& s : B) {
            unordered_map <int, int> freqMap;
            for (int i = 0; i < s.length(); i++) {
                freqMap[s[i]] ++;
            }
            for(auto entry : freqMap) {
                maxFreqMap[entry.first] = max(maxFreqMap[entry.first], entry.second);
            }
        }
        
        vector<string> result;
        for(int i = 0; i < n; i++) {
            bool isUniversal = true;
            for(auto entry : maxFreqMap) {
                if(freqMap[i][entry.first] < entry.second) {
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) {
                result.push_back(A[i]);
            }
        }
            
        return result;
    }
};