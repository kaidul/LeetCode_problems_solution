class WordDistance {
    unordered_map<string, vector<int> > pos;
    
    int lowerBound(int left, int right, const int value, vector<int> const& container) {
        if(left >= right) {
            return left;
        }    
        int mid = left + (right - left) / 2;
        if(value <= container[mid]) {
            return lowerBound(left, mid, value, container);
        } else if(value > container[mid]) {
            return lowerBound(mid + 1, right, value, container);
        }
    }
    
    int upperBound(int left, int right, const int value, vector<int> const& container) {
        if(left >= right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if(value < container[mid]) {
            return upperBound(left, mid, value, container);
        } else if(value >= container[mid]) {
            return upperBound(mid + 1, right, value, container);
        }
    }
    
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            pos[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int n = pos[word1].size();
        int m = pos[word2].size();
        
        if(pos[word1][n - 1] < pos[word2][0]) {
            return (pos[word2][0] - pos[word1][n - 1]);
        }
        if(pos[word1][0] > pos[word2][m - 1]) {
            return (pos[word1][0] - pos[word2][m - 1]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int upper = upperBound(0, pos[word2].size() - 1, pos[word1][i], pos[word2]);
            ans = min(ans, abs(pos[word2][upper] - pos[word1][i]));
            // we don't need to calculate lower bound, because there is no equal_range
            // so, immediate previous index of upper bound is lower bound
            // int lower = lowerbound(pos[word2], pos[word1][i]);
            if(upper > 0) {
                ans = min(ans, abs(pos[word2][upper - 1] - pos[word1][i]));
            }
        }
        return ans;
    }
};

// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");