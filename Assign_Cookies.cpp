class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for(int k = 0; i < g.size() and k < s.size(); ++k) {
            if(g[i] <= s[k]) {
                i++;
            }
        }
        return i;
    }
};