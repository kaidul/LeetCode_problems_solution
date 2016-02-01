class Solution {
public:
    int lowerBound(int left, int right, const int value, vector<int> const& container) {
        if(left >= right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if(value <= container[mid]) {
            return lowerBound(left, mid, value, container);
        } else if (value > container[mid]) {
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

    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<vector<int> > pos(2, vector<int>());
        for(int i = 0; i < words.size(); ++i) {
            if(words[i] == word1) {
                pos[0].push_back(i);
            } else if(words[i] == word2) {
                pos[1].push_back(i);
            }
        }
        int n = pos[0].size();
        int m = pos[1].size();
        
        if(pos[0][n - 1] < pos[1][0]) {
            return (pos[1][0] - pos[0][n - 1]);
        }
        if(pos[0][0] > pos[1][m - 1]) {
            return (pos[0][0] - pos[1][m - 1]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int upper = upperBound(0, pos[1].size() - 1, pos[0][i], pos[1]);
            ans = min(ans, abs(pos[1][upper] - pos[0][i]));
            int lower = lowerBound(0, pos[1].size() - 1, pos[0][i], pos[1]);
            if(lower > 0) {
                ans = min(ans, abs(pos[1][lower - 1] - pos[0][i]));
            }
        }
        return ans;
    }
};