class Solution {
public:
    int lowerbound(vector<int>& v, int val) {
        int st = 0;
        int en = v.size() - 1;
        int idx, cnt, stp;
        cnt = en - st;
        while(cnt > 0) {
            stp = cnt >> 1; idx = st + stp;
            if(v[idx] < val) st = ++idx, cnt -= stp+1;
            else cnt = stp;
        }
        return st;
    }
 
    int upperbound(vector<int>& v, int val) {
        int st = 0;
        int en = v.size() - 1;
        int idx, cnt, stp;
        cnt = en - st;
        while(cnt > 0) {
            stp = cnt >> 1; idx = st + stp;
            if(v[idx] <= val) st = ++idx, cnt -= stp+1;
            else cnt = stp;
        }
        return st;
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
            int upper = upperbound(pos[1], pos[0][i]);
            ans = min(ans, abs(pos[1][upper] - pos[0][i]));
            int lower = lowerbound(pos[1], pos[0][i]);
            if(lower > 0) {
                ans = min(ans, abs(pos[1][lower - 1] - pos[0][i]));
            }
        }
        return ans;
    }
};