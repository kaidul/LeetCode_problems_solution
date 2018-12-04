class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> order(30, -1);
        vector<int> letter(30);
        for (int i = 0; i < (int) S.length(); i++) {
            order[S[i] - 'a'] = i;
            letter[i] = S[i] - 'a';
        }
        string result = "";
        vector<int> count(30, 0);
        for (int i = 0; i < (int)T.length(); i++) {
            if(order[T[i] - 'a'] != -1) {
                count[order[T[i] - 'a']]++;    
            } else {
                result += T[i];
            }
        }
        for (int i = 0; i < 26; i++) {
            while (count[i]--) {
                result += ('a' + letter[i]);
            }
        }
        
        return result;
    }
};