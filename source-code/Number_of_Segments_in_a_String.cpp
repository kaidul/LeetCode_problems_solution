class Solution {
public:
    /**
    int countSegments(string s) {
        int count = 0;
        const char WHITESPACE = ' ';
        int start = 0;
        while(start < s.length()) {
            int indx = s.find(WHITESPACE, start);
            if(indx == string::npos or indx > start) { count++; }
            if(indx == string::npos) return count;
            start = indx + 1;
        }
        return count;
    }
    **/
    int countSegments(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            int start = i;
            while(i < s.length() and s[i] != ' ') {
                i++;
            }
            cnt += (i > start);
        }
        return cnt;
    }
};