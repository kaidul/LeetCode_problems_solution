class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for(auto &word : words) {
            waiting[word[0]].push_back(word.c_str());
        }
        for(char ch : S) {
            auto suffixes = waiting[ch];
            waiting[ch].clear();
            for(auto it : suffixes) {
                auto advance = *++it;
                waiting[advance].push_back(it);
            }
        }
        
        return waiting[0].size();
    }
};