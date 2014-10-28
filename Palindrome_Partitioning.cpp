class Solution {
public:
 
    bool isPalindrome(string &str, int start, int end) {
        while (start < end) {
            if (str[end--] != str[start++]) {
                return false;
            }
        }
        return true;
    }
 
     
    void partitionUtils(string s, int start, vector<string> &r, vector<vector<string> > &res) {
        if (start >= s.size()) {
            res.push_back(r);
            return;
        }
        for (int i = start; i < s.size(); i++) {            
            if(isPalindrome(s, start, i) ) {
                r.push_back(s.substr(start, i - start + 1));
                partitionUtils(s, i + 1, r, res);        
                r.pop_back();
            }
        }
    }
 
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> r;
        partitionUtils(s, 0, r, res);
        return res;
    }
};