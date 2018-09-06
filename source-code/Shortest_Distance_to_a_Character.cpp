class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int latestPositionOfC = INT_MAX;
        vector<int> result(S.length(), INT_MAX);
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == C) { 
                latestPositionOfC = i;
            }
            if(latestPositionOfC != INT_MAX) {
                result[i] = i - latestPositionOfC;
            }
        }
        latestPositionOfC = INT_MAX;
        for(int i = S.length() - 1; i >= 0; i--) {
            if(S[i] == C) { 
                latestPositionOfC = i;
            }
            if(latestPositionOfC != INT_MAX) {
                result[i] = min(result[i], latestPositionOfC - i);
            }
        }
        
        return result;
    }
};