// O(nlogk) time and O(n) space
class Solution {
    class Compare {
    public:
        bool operator() (pair<int, string> const& p, pair<int, string> const& q) {
            if(p.first == q.first) {
                return p.second < q.second;
            }
            return p.first > q.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = (int)words.size();
        unordered_map<string, int> freq;
        for(string& word: words) {
            freq[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pQ;
        for(auto entry = freq.begin(); entry != freq.end(); entry++) {
            if(pQ.size() < k) {
                pQ.push({entry->second, entry->first});
            } else {
                if((pQ.top().first < entry->second) or
                    (pQ.top().first == entry->second and entry->first < pQ.top().second)) {
                    pQ.pop();
                    pQ.push({entry->second, entry->first});
                }
            }
        }
        vector<string> result(k);
        while(!pQ.empty()) {
            result[--k] = pQ.top().second;
            pQ.pop();
        }
        return result;
    }
};