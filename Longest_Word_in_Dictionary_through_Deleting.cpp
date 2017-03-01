class Solution {
    bool isSubseq(string const& txt, string const& subseq) {
        int n = (int)txt.length();
        int m = (int)subseq.length();
        if(m > n) return false;
        int i = 0, j = 0;
        while(i < n and j < m) {
            if(subseq[j] == txt[i]) {
                j++, i++;
            } else {
                i++;
            }
        }
        return j == m;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        int maxLen = 0;
        sort(d.begin(), d.end());
        for(int i = 0; i < (int)d.size(); i++) {
            if(d[i].length() > result.length() and isSubseq(s, d[i])) {
                maxLen = (int)d[i].length();
                result = d[i];
            }
        }
        
        return result;
    }
};