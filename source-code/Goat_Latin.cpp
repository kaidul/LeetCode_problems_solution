class Solution {
    bool isVowel(char ch) {
        switch(tolower(ch)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
        }
    }
public:
    string toGoatLatin(string S) {
        if(S.empty()) return S;
        int start = 0;
        string result;
        string suffix = "a";
        while(start < S.length()) {
            int end = S.find(' ', start);
            if(end == string::npos) {
                end = (int)S.length();
            }
            string word = S.substr(start, end - start);
            if(isVowel(word[0])) {
                word += "ma";
            } else {
                word += word[0];
                word += "ma";
                word = word.substr(1);
            }
            word += suffix;
            result += word;
            result += ' ';
            suffix += 'a';
            start = end + 1;
        }
        return result.substr(0, result.length() - 1); // or return result.erase(result.length() - 1, 1);
    }
};