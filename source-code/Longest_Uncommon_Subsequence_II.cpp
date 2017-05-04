class Solution {
    bool isSubseq(string const& s1, string const& s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        int j = 0;
        for(int i = 0; i < (int)s2.length() and j < (int)s1.length(); i++) {
            if(s2[i] == s1[j]) {
                j++;
            }
        }
        return j == (int)s1.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        int result = -1;
        unordered_set<string> exist;
        for(int i = 0; i < (int)strs.size(); i++) {
            
            // silly prune
            if(exist.find(strs[i]) != exist.end() or (int)strs[i].length() <= result) {
                continue;
            }

            bool flag = true;
            for(int j = 0; j < (int)strs.size() and flag; j++) {
                if(i == j) continue;
                if(isSubseq(strs[i], strs[j])) {
                    flag = false;
                }
            }
            exist.insert(strs[i]);
            if(flag) {
                result = max(result, (int)strs[i].length());
            }
        }
        return result;
    }
};