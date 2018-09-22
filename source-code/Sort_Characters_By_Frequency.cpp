class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        const int MAX_CHAR = 256;
        vector<int> freq(MAX_CHAR, 0);
        for(int i = 0 ; i < n; ++i) {
            freq[s[i]]++;
        }
#if 0
        // bucket sort
        vector<vector<int>> bucket(n + 1);
        for (int i = 0; i < MAX_CHAR; i++) {
            bucket[freq[i]].push_back(i);    
        }
        string result = "";
        for (int i = bucket.size() - 1; i > 0; i--) {
            for (auto ch : bucket[i]) {
                result += string(i, ch);    
            }
        }
#endif
        // auto compare = [] (pair<int, int> const& lhs, pair<int, int> const& rhs) -> bool const { return lhs.first < rhs.first; };
        // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> Q(compare);
        priority_queue<pair<int, int>> Q;
        for(int i = 0 ; i < MAX_CHAR; ++i) {
            if(freq[i] > 0) {
                Q.push({freq[i], i});
            }
        }
        string result = "";
        while(!Q.empty()) {
            result += string(Q.top().first, Q.top().second);
            Q.pop();
        }
        return result;
    }
};