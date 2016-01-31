class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs[0].length(); ++i) {
            for(int j = 0; j < strs.size() - 1; j++) {
                if(i >= strs[j + 1].length() or strs[j][i] != strs[j + 1][i])
                    return strs[j].substr(0, i);
            }
        }
        return strs[0];
    }
};