class Solution {
public:
    void countingSort(string& str) {
        size_t len = str.length();
        char output[len];

        const int RANGE = 26;
        int count[RANGE + 1];
        memset(count, 0, sizeof(count));
        
        for(int i = 0; i < len; ++i) ++count[str[i] - 'a'];
 
        for (int i = 1; i <= RANGE; ++i) count[i] += count[i - 1];
 
        for (int i = 0; i < len; ++i) {
            output[count[str[i] - 'a'] - 1] = str[i];
            --count[str[i] - 'a'];
        }
 
        for (int i = 0; i < len; ++i) str[i] = output[i];
    }

    bool isAnagram(string s, string t) {
        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        */
        countingSort(s);
        countingSort(t);
        return s == t;
    }
};